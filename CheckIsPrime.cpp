#include <iostream>
#include <cmath>

using ll = long long;

const int maxn = (int)1e7;

int prime[maxn + 1];

void sang() {
    for (int i{0}; i <= maxn; i++) {
        prime[i] = 1;
    }
    prime[0] = prime[1] = 0;
    for (int i{2}; i <= sqrt(maxn); i++) {
        if (prime[i]) {
            for (int j = i * i; j < maxn; j += i) {
                prime[j] = 0;
            }
        }
    }
}

bool isPrime(int n) {
    if ( 1 < n ) {
        if ( n < 4 ) {
            return true;
        } else {
            for (int i {2}; i <= sqrt(n); i++) {
                if (n % i == 0) {
                    return false;
                }
            }
            return true;
        }
    } else return false;
};

bool check(int n) {
    int last = n % 10;
    while (n) {
        if (n % 10 > last) {
            return false;
        }
        n /= 10;
    }
    return true;
};

int main()
{
    // int count = 0;
    // for ( int i = 1; i <= 300; i++ ) {
    //     if (isPrime(i)) {
    //         // if (check(i)) {
    //         count++;
    //         std::cout << i << " ";
    //         // }
    //     }
    // }
    // std::cout << std::endl;
    // // std::cout << isPrime(200);
    // std::cout << std::endl;
    // std::cout << count;
    sang();
    int n;
    std::cin >> n;
    int count = 0;
    for (int i{1}; i <= n; i++) {
        if (prime[i] && check(i)) {
            count++;
            std::cout << i << " ";
        }
    }
    std::cout << std::endl << count << std::endl;
};