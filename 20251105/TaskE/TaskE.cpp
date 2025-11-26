#include <iostream>
#include <stdlib.h>
#include <time.h>

const int DATA_VOLUME = 11;
const int TARGET = 5;

int main()
{
    // 初期化  
    srand(time(NULL));

    // 1
    int data[DATA_VOLUME];

    for(int i = 0;i < DATA_VOLUME;i++)
    {
        data[i] = i;
    }

    // 2
    //データのかき混ぜ
    for (int i = 0;i < DATA_VOLUME;i++)
    {
        int changeIndex = rand() % DATA_VOLUME;
        int saveNum;

        saveNum = data[i];
        data[i] = data[changeIndex];
        data[changeIndex] = saveNum;
    }

    // 3
    int result = -1;

    // 4
    for(int i = 0;i < DATA_VOLUME;i++)
    {
        if(data[i] == TARGET)
        {
            result = i;
            break;
        }
    }

    // 5
    std::cout << TARGET << "のインデックスは" << result << "です" << std::endl;



    return 0;
}