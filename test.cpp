#include <iostream>
#include <typeinfo>
#include <map>
#include <vector>


void tic_toc_game(std::vector<char> player_choice)
{
    std::cout << ' ' << player_choice[0]<< " | " << player_choice[1] <<" | " << player_choice[2] << ' ' << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << ' ' << player_choice[3]<< " | " << player_choice[4] <<" | " << player_choice[5] << ' ' << std::endl;
    std::cout << "---|---|---" << std::endl;
    std::cout << ' ' << player_choice[6]<< " | " << player_choice[7] <<" | " << player_choice[8] << ' ' << std::endl;
}

int main()
{

    std::map<int, int> check_list[8];
    check_list[0][1] = 0;
    check_list[0][2] = 1;
    check_list[0][3] = 2;
    check_list[1][1] = 3;
    check_list[1][2] = 4;
    check_list[1][3] = 5;
    check_list[2][1] = 6;
    check_list[2][2] = 7;
    check_list[2][3] = 8;
    check_list[3][1] = 0;
    check_list[3][2] = 3;
    check_list[3][3] = 6;
    check_list[4][1] = 1;
    check_list[4][2] = 4;
    check_list[4][3] = 7;
    check_list[5][1] = 2;
    check_list[5][2] = 4;
    check_list[5][3] = 6;
    check_list[6][1] = 0;
    check_list[6][2] = 4;
    check_list[6][3] = 8;
    check_list[7][1] = 2;
    check_list[7][2] = 4;
    check_list[7][3] = 6;

    std::vector<char> position {'1', '2', '3', '4', '5', '6', '7', '8', '9'};
    int choice;
    int turn{0};
    tic_toc_game(position);
    while (turn < 9) {
        if (turn % 2 == 0) {
            std::cout << "Player 1, please choose a number to write down X: ";
            std::cin >> choice;
        if ( (position[choice - 1] != 'X') && (position[choice - 1] != 'O') ) {
            position[choice-1] = 'X';
            turn++;
        } 
        } else {
        std::cout << "Player 2, please choose a number to write down O: ";
        std::cin >> choice;
        if ( (position[choice - 1] != 'X') && (position[choice - 1] != 'O') ) {
            position[choice-1] = 'O';
            turn++;
        }
        }
        tic_toc_game(position);
        for (int i = 0; i < 8; i++) {
            if ( ( position[check_list[i][1]] == position[check_list[i][2]] ) && ( position[check_list[i][1]] == position[check_list[i][3]] ) ) {
                if ( position[check_list[i][1]] == 'X' ) std::cout << "Player 1 wins!" << std::endl;
                else std::cout << "Player 2 wins!" << std::endl;
                turn = 9;
            }
        }
    }
}