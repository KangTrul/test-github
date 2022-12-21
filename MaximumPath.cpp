#include <iostream>
#include <algorithm>

int main()
{
    int n = 0;
    std::cout << "Input value to n (1 <= n <= 100): ";
    std::cin >> n;
    while (n <= 0 || n > 100) {
        std::cout << "Input again: ";
        std::cin >> n;
    }
    int arr[n][n];
    std::cout << "New matrix has just been created. It has [i][j] with i (equals to n) rows and j (equals to n) columns.\n";
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cout << "Input value to position " << "[" << i << "]" << "[" << j << "]: ";
            std::cin >> arr[i][j];
        }
    }
    for (int i{0}; i < n; i++) {
        for (int j{0}; j < n; j++) {
            std::cout << arr[i][j] << " ";
        }
        std::cout << std::endl;
    }
    int coverArr[n+2][n];
    for (int i{1}; i < n+1; i++) {
        coverArr[i][0] = arr[i-1][0];
        coverArr[0][i-1] = coverArr[n+1][i-1] = -1e9;
    }
    // for (int i{1}; i < n+1; i++) {
    //     for (int j{1}; j < n; j++) {
    //         coverArr[i][j] = std::max({coverArr[i-1][j-1], coverArr[i][j-1], coverArr[i+1][j-1]}) + arr[i-1][j];
    //     }
    // }
    
    for (int j{1}; j < n; j++) {
        for (int i{1}; i < n+1; i++) {
            coverArr[i][j] = std::max({coverArr[i-1][j-1], coverArr[i][j-1], coverArr[i+1][j-1]}) + arr[i-1][j];
        }
    }
    for (int i{0}; i < n+2; i++) {
        for (int j{0}; j < n; j++) {
            std::cout << coverArr[i][j] << " ";
        }
        std::cout << std::endl;
    }
}