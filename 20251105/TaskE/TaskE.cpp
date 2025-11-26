#include <iostream>
#include <stdlib.h>
#include <time.h>

int main()
{
    const int DataVolume = 11;
    int data[DataVolume];

    for(int i = 0;i < DataVolume;i++)
    {
        data[i] = i;
    }

    srand(time(NULL));

    //データのかき混ぜ
    for (int i = 0;i < DataVolume;i++)
    {
        int changeIndex = rand() % DataVolume;
        int saveNum;

        saveNum = data[i];
        data[i] = data[changeIndex];
        data[changeIndex] = saveNum;
    }

        for(int i = 0;i < DataVolume;i++)
    {
        std::cout << data[i] << std::endl;
    }

    return 0;
}