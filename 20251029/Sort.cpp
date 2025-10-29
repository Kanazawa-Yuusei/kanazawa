#include<iostream>
#include <stdlib.h>
#include<time.h>

int main()
{
    srand(time(nullptr));

    int sortNumbers[10];
    int numbersIndex = 10;
    int minNumber;

    for (int i = 0;i < numbersIndex;i++)
    {
        sortNumbers[i] = rand() % 100 + 1;
    }
    
    for (int i = 0;i < numbersIndex;i++)
    {
        std::cout << sortNumbers[i];
        std::cout << "　";
    }
    std::cout << std::endl;

    for (int i= 0;i < numbersIndex - 1;i++)
    {
        minNumber = sortNumbers[i];

        for (int j = i;j < numbersIndex;j++)
        {
            if (minNumber > sortNumbers[j])
            {
                minNumber = sortNumbers[j];
                sortNumbers[j] = sortNumbers[i];
                sortNumbers[i] = minNumber;
            }
        }
    }

    for (int i = 0;i < numbersIndex;i++)
    {
        std::cout << sortNumbers[i];
        std::cout << "　";
    }
    std::cout << std::endl;

    return 0;
}