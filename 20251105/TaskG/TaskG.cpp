#include<iostream>
#include <stdlib.h>
#include <time.h>

const int DATA_VOLUME = 100;

int main()
{
    //dataの用意
    srand(time(NULL));

    int data[DATA_VOLUME];

    for(int i = 0; i < DATA_VOLUME; i++)
    {
        data[i] = rand() % (DATA_VOLUME + 1);
    }

    //dataのソート
    for(int i = 0;i < DATA_VOLUME - 1;i++)
    {
        for(int j = i + 1;j < DATA_VOLUME;j++)
        {
            if(data[i] > data[j])
            {
                int min = data[j];
                int max = data[i];

                data[i] = min;
                data[j] = max;
            }
        }
    }

    int target = 50;
    int result = -1;
    int left = 0;
    int right = DATA_VOLUME - 1;

    //targetが存在するかと存在するときインデックスを調べる
    for(int i = left;i < right;)
    {
        int mid = (left + right) / 2;

        if (data[mid] == target)
        {
            result == mid;
            break;
        }
        else
        {
            if(data[mid] < target)
            {
                right = mid;
            }
            else
            {
                left = mid + 1;
                i = left;
            }
        }
    }

    if(result >= 0)
    {
        std::cout << target;
        std::cout << "のインデックスは";
        std::cout << result;
        std::cout << "です" << std::endl;
    }
    else if(result < 0)
    {
        std::cout << target;
        std::cout <<  "は見つかりませんでした" << std::endl;
    }

    return 0;
}