#include<iostream>
#include<string.h>
#include<stdlib.h>
#include<time.h>

using namespace std;



int main()
{
    srand(time(NULL));

    char charactor[50];
    char alphabet = 'A';
    int index = 0;

    for(char alphabet = 'A'; alphabet <= 'Z'; alphabet++)
    {

        // スタックの処理を作る
        charactor[index] = alphabet;


        // 追加する文字と追加した配列を表示
        cout << "追加する文字   ";
        cout << alphabet << endl;
        cout << "追加後の配列" << endl;
        for (int i = 0; i <= index;i++)
        {
            cout << charactor[i];
            cout << ", ";
        }
        cout << endl;

        bool doTakeAlphabet = rand() % 2 == 1;
        if(doTakeAlphabet == true)
        {
            // 取り出す処理
            cout << "取り出す文字   ";
            cout << charactor[index] << endl;
            charactor[index] = '\0';
            cout << "取り出した後の配列" << endl;
            for (int i = 0; i <= index;i++)
            {
                cout << charactor[i];
                cout << ", ";
            }
            cout << endl;
        }
        else
        {
            index++;
        }
    }


    return 0;
}