#include<iostream>
#include <stdlib.h>
#include <time.h>

const int DATA_VOLUME = 100;

int main()
{
    srand(time(NULL));

    int data[DATA_VOLUME];

    for(int i = 0; i < DATA_VOLUME; i++)
    {
        data[i] = rand() % DATA_VOLUME;
    }

    for(int i = 0; i < DATA_VOLUME; i++)
    {
        for(int j = DATA_VOLUME - 1; j >= i + i;j--)
        {
            int valueA = data[i];
            int valueB = data[j];

            if (valueA > valueB)
            {
                int max = valueA;
                int min = valueB;

                data[i] = min;
                data[j] = max;
            }
        }
    }

    for (int i = 0;i < DATA_VOLUME;i++)
    {
        std::cout << data[i] << std::endl;
    }


    return 0;
}