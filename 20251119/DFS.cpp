#include <iostream>

using namespace std;

int map[8][8] = {
    { 1, 1, 0, 1, 1, 1, 1, 1 },
    { 1, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 0, 0, 1, 0, 1, 0, 1 },
    { 1, 1, 2, 1, 0, 1, 0, 1},
    { 1, 0, 1, 1, 0, 0, 1, 1},
    { 1, 0, 1, 0, 0, 1, 1, 0},
    { 1, 1, 1, 0, 0, 0, 3, 0},
    { 1, 0, 1, 1, 1, 0, 1, 0},
};

int nowPos[2] = { 3, 2 };
int canGoPos[100][2] = {0};
int canGoIndex = 0;
int WentPos[100][2] = {0};
int wentIndex = 0;

bool canSearch;
bool checkGoal;

bool searchCanGoPos(int nowPosRow, int nowPosCol);

int main()
{
    // 探索の処理
    do{
        // 行ける座標の取得とゴールチェック
        checkGoal = searchCanGoPos(nowPos[0], nowPos[1]);
        if(checkGoal)break;
        // 現在の座標を行った座標に追加
        WentPos[wentIndex][0] = nowPos[0];
        WentPos[wentIndex][1] = nowPos[1];
        wentIndex++;

        // 探索できる場所があるか
        if( canGoIndex <= 0)
        {
            canSearch = false; // ない
        }
        else
        {
            canSearch = true; // ある

            //行ける座標の配列の最後のマスを現在の座標に更新する
            nowPos[0] = canGoPos[canGoIndex - 1][0];
            nowPos[1] = canGoPos[canGoIndex - 1][1];
            canGoIndex--;
        }

        

    }while (canSearch);

    if(checkGoal)
    {
        cout << "ゴールを発見しました" << endl;
    }
    else
    {
        cout << "ゴールは見つかりませんでした" << endl;
    }

}

//行ける座標のチェックとゴールチェック
bool searchCanGoPos(int nowPosRow, int nowPosCol)
{
    int searchRow = 0;
    int searchCol = 0;

    // 現在地から右の座標チェック
    if(nowPos[1] != 7)
    {
        searchRow = nowPos[0];
        searchCol = nowPos[1] + 1;

        bool wentPosCheck = false;

        // 通ったマスかのチェック
        for (int i = 0; i < wentIndex; i++)
        {
            if(WentPos[i][0] == searchRow
            && WentPos[i][1] == searchCol)
            {
                wentPosCheck = true;
            }
        }

        // 通ったマスでない
        if(!wentPosCheck)
        {
            if(map[searchRow][searchCol] == 3) // ゴールだったら
            {
                return true;
            }
            else if(map[searchRow][searchCol] == 1) // ゴールではないけど行ける座標だったら
            {
                canGoPos[canGoIndex][0] = searchRow;
                canGoPos[canGoIndex][1] = searchCol;
                canGoIndex++;
            }            
        }

    }

    // 現在地から下の座標のチェック
    if(nowPos[0] != 7)
    {
        searchRow = nowPos[0] + 1;
        searchCol = nowPos[1];

        bool wentPosCheck = false;

        // 通ったマスかのチェック
        for (int i = 0; i < wentIndex; i++)
        {
            if(WentPos[i][0] == searchRow
            && WentPos[i][1] == searchCol)
            {
                wentPosCheck = true;
            }
        }

        // 通ったマスでない
        if(!wentPosCheck)
        {
            if(map[searchRow][searchCol] == 3) // ゴールだったら
            {
                return true;
            }
            else if(map[searchRow][searchCol] == 1) // ゴールではないけど行ける座標だったら
            {
                canGoPos[canGoIndex][0] = searchRow;
                canGoPos[canGoIndex][1] = searchCol;
                canGoIndex++;
            }
        }
    }

    // 現在地から左の座標のチェック
    if(nowPos[1] != 0)
    {
        searchRow = nowPos[0];
        searchCol = nowPos[1] - 1;

        bool wentPosCheck = false;

        // 通ったマスかのチェック
        for (int i = 0; i < wentIndex; i++)
        {
            if(WentPos[i][0] == searchRow
            && WentPos[i][1] == searchCol)
            {
                wentPosCheck = true;
            }
        }

        // 通ったマスでない
        if(!wentPosCheck)
        {
            if(map[searchRow][searchCol] == 3) // ゴールだったら
            {
                return true;
            }
            else if(map[searchRow][searchCol] == 1) // ゴールではないけど行ける座標だったら
            {
                canGoPos[canGoIndex][0] = searchRow;
                canGoPos[canGoIndex][1] = searchCol;
                canGoIndex++;
            }
        }
    }

    // 現在地から上の座標のチェック
    if(nowPos[0] != 0)
    {
        searchRow = nowPos[0] - 1;
        searchCol = nowPos[1];

        bool wentPosCheck = false;

        // 通ったマスかのチェック
        for (int i = 0; i < wentIndex; i++)
        {
            if(WentPos[i][0] == searchRow
            && WentPos[i][1] == searchCol)
            {
                wentPosCheck = true;
            }
        }

        // 通ったマスでない
        if(!wentPosCheck)
        {
            if(map[searchRow][searchCol] == 3) // ゴールだったら
            {
                return true;
            }
            else if(map[searchRow][searchCol] == 1) // ゴールではないけど行ける座標だったら
            {
                canGoPos[canGoIndex][0] = searchRow;
                canGoPos[canGoIndex][1] = searchCol;
                canGoIndex++;
            }
        }
    }

    cout << "行ける座標" << endl;
    for (int i = 0; i < canGoIndex; i++)
    {
        cout << "(";
        cout << canGoPos[i][0];
        cout << ", ";
        cout << canGoPos[i][1];
        cout << "), ";
    }
    cout << endl;

    return false;
}   

