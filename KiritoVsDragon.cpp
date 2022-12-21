#include <iostream>
#include <sstream>
#include <vector>
#include <typeinfo>
#include <list>
#include <string>
#include <locale>

#define maxS  (int)1e6;
#define maxN  (int)1e5;
#define maxXi (int)1e4;
#define maxYi (int)1e4;

struct dragonsPowerAndBonusPoint{
    int dp;     // dragon's power
    int bp;     // bonus point
};

int main()
{
    long long kiritosPower;
    int numsOfDragon, dragonsPower, bonusPoint;
    std::string sn, xiyi;
    std::cout << "Input Kiroto's power and the number of dragon (follow this format \"s n\"): ";
    std::getline(std::cin, sn);

    int kiritosPowerAndNumsOfDragonList[2] = {0, 0};
    int count {0};
    std::stringstream ss(sn);
    while (ss.good() && count < 2) {
        ss >> kiritosPowerAndNumsOfDragonList[count];
        count++;
    }
    kiritosPower = kiritosPowerAndNumsOfDragonList[0];
    numsOfDragon = kiritosPowerAndNumsOfDragonList[1];

    std::cout << kiritosPower << " " << numsOfDragon << std::endl;

    dragonsPowerAndBonusPoint dragonsPowerAndBonusPointList[numsOfDragon];

    for (size_t i{0}; i < numsOfDragon; i++) {
        std::cout << i + 1 << ": Input Dragon's power and the bonus point (follow this format \"s n\"): ";
        std::getline(std::cin, xiyi);

        count = 0;

        std::stringstream ss2(xiyi);
        while (ss2.good() && count < 2) {
            if (count == 0) ss2 >> dragonsPowerAndBonusPointList[i].dp;
            else ss2 >> dragonsPowerAndBonusPointList[i].bp;
            count++;
        }
        std::cout << i + 1 << ": " << dragonsPowerAndBonusPointList[i].dp << " " << dragonsPowerAndBonusPointList[i].bp << std::endl;
    }

    dragonsPowerAndBonusPoint tempStruct;
    for (size_t i{0}; i < numsOfDragon - 1; i++) {
        for (size_t j{i + 1}; j < numsOfDragon; j++) {
            if (dragonsPowerAndBonusPointList[i].dp > dragonsPowerAndBonusPointList[j].dp) {
                tempStruct = dragonsPowerAndBonusPointList[i];
                dragonsPowerAndBonusPointList[i] = dragonsPowerAndBonusPointList[j];
                dragonsPowerAndBonusPointList[j] = tempStruct;
            }
        }
    }

    for (size_t i{0}; i < numsOfDragon; i++) {
        if (kiritosPower > dragonsPowerAndBonusPointList[i].dp) {
            kiritosPower += dragonsPowerAndBonusPointList[i].bp;
            std::cout << "Win dragon number: " << i + 1 << std::endl;
            std::cout << "Kiroto's Power: " << kiritosPower << std::endl;
        } else {
            std::cout << "LOSE";
            break;
        }
    }

    // Short solution:
    /*
    ll n, s;
    cin >> n >> s;
    std::pair<int, int> a[n];
    for (int i = 0; i < n; i++) {
        cin >> a[i].first >> a[i].second;
    }
    std::sort(a, a + n);
    for (int i = 0; i < n; i++) {
        if (s <= a[i].first) {
            cout << "NO\n";
            return 0;
        }
        s += a[i].second;
    }
    std::cout << "YES\n";
    */
}