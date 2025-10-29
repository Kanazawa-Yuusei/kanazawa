#include<iostream>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(nullptr));
    int sortNumbers[10];

    for (int i = 0;i < 10;i++)
    {
        sortNumbers[i] = rand() % 100 + 1;
    }
    
        for (int i = 0;i < 10;i++)
    {
        std::cout << sortNumbers[i];
        std::cout << "　";
    }
    std::cout << std::endl;
}