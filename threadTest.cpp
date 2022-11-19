#include <thread>
#include <iostream>

void func()
{
    std::cout<< "Welcome to Multithreading" << std::endl;
}

int main()
{
    std::thread funcTest(func);
}