#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    srand(time(nullptr));
    const int DataVolume = 10;
    int data[DataVolume];

    for (int i = 0;i < DataVolume;i++)
    {
        data[i] = rand() % 100 + 1;
    }

    for (int i = 0;i < DataVolume;i++)
    {
        std::cout << data[i] << std::endl;
    }

    return 0;
}