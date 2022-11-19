#include <iostream>

int (*funcPointer)(int, int) ;

int sum(int a, int b)
{
    return a + b;
}

void showResult(int (*fptr)(int, int), int a, int b)
{
    std::cout << fptr(a, b) << std::endl;
}

int main()
{
    funcPointer = sum;
    showResult(funcPointer, 12, 51);
    return 0;
}