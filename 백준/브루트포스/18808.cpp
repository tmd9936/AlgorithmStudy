#include<bits/stdc++.h>
using namespace std;

int nx[5] = {0, 1, 0, -1, 0 };
int ny[5] = {0, 0, 1, 0, -1 };

int col, row;
int stickerNum = 0;
int result = 0;

struct Sticker
{
    int col = 0;
    int row = 0;
    vector<vector<int>> arr;
};

int note[40][40] = { 0 };
vector<Sticker> stickers;

bool upd1(int i, int j, int stkIdx, const pair<int, int>& stPoint)
{
    queue<pair<int, int>> stickerPoint;
    stickerPoint.push(stPoint);

    Sticker temp = stickers[stkIdx];
    //temp.arr[stPoint.first][stPoint.second] = -1;

    while (!stickerPoint.empty())
    {
        pair<int, int> p = stickerPoint.front();
        stickerPoint.pop();

        for (int k = 0; k < 5; ++k)
        {
            int x = p.second + nx[k];
            int y = p.first + ny[k];
            if (x < 0 || x >= stickers[stkIdx].row || y < 0 || y >= stickers[stkIdx].col)
                continue;
            if (temp.arr[y][x] == 0 || temp.arr[y][x] == -1)
                continue;
            if (x + j >= row || y + i >= col || note[y + i][x + j] == 1)
                return false;

            temp.arr[y][x] = -1;
            if (k != 0)
            {
                stickerPoint.push({ y, x });
            }
        }
    }

    int stk_row = stickers[stkIdx].row;
    int stk_col = stickers[stkIdx].col;

    for (int c = 0; c < stk_col; ++c)
    {
        for (int r = 0; r < stk_row; ++r)
        {
            if (stickers[stkIdx].arr[c][r] == 1)
                note[i + c][j + r] = stickers[stkIdx].arr[c][r];
        }
    }

    return true;
}

bool upd2(int i, int j, int stkIdx, const pair<int, int>& stPoint)
{
    queue<pair<int, int>> stickerPoint;
    stickerPoint.push(stPoint);

    Sticker temp = stickers[stkIdx];
    //temp.arr[stPoint.first][stPoint.second] = -1;

    while (!stickerPoint.empty())
    {
        pair<int, int> p = stickerPoint.front();
        stickerPoint.pop();

        for (int k = 0; k < 5; ++k)
        {
            int x = p.second + nx[k];
            int y = p.first + ny[k];
            if (x < 0 || x >= stickers[stkIdx].row || y < 0 || y >= stickers[stkIdx].col)
                continue;
            if (temp.arr[y][x] == 0 || temp.arr[y][x] == -1)
                continue;
            if (stickers[stkIdx].col - y - 1 + j >= row || x + i >= col
                || note[x + i][stickers[stkIdx].col - y - 1 + j] == 1)
                return false;

            temp.arr[y][x] = -1;
            if (k != 0)
            {
                stickerPoint.push({ y, x });
            }
        }
    }

    int stk_row = stickers[stkIdx].row;
    int stk_col = stickers[stkIdx].col;

    for (int c = 0; c < stk_col; ++c)
    {
        for (int r = 0; r < stk_row; ++r)
        {
            if (stickers[stkIdx].arr[c][r] == 1)
                note[r + i][stickers[stkIdx].col - c - 1 + j] = stickers[stkIdx].arr[c][r];
        }
    }

    return true;
}

bool upd3(int i, int j, int stkIdx, const pair<int, int>& stPoint)
{
    queue<pair<int, int>> stickerPoint;
    stickerPoint.push(stPoint);

    Sticker temp = stickers[stkIdx];
    //temp.arr[stPoint.first][stPoint.second] = -1;

    while (!stickerPoint.empty())
    {
        pair<int, int> p = stickerPoint.front();
        stickerPoint.pop();

        for (int k = 0; k < 5; ++k)
        {
            int x = p.second + nx[k];
            int y = p.first + ny[k];
            if (x < 0 || x >= stickers[stkIdx].row || y < 0 || y >= stickers[stkIdx].col)
                continue;
            if (temp.arr[y][x] == 0 || temp.arr[y][x] == -1)
                continue;
            if (stickers[stkIdx].row - x - 1 + j >= row ||
                stickers[stkIdx].col - y - 1 + i >= col ||
                note[stickers[stkIdx].col - y - 1 + i][stickers[stkIdx].row - x - 1 + j] == 1)
                return false;

            temp.arr[y][x] = -1;
            if (k != 0)
            {
                stickerPoint.push({ y, x });
            }
        }
    }

    int stk_row = stickers[stkIdx].row;
    int stk_col = stickers[stkIdx].col;

    for (int c = 0; c < stk_col; ++c)
    {
        for (int r = 0; r < stk_row; ++r)
        {
            if (stickers[stkIdx].arr[c][r] == 1)
                note[stickers[stkIdx].col - c - 1 + i][stickers[stkIdx].row - r - 1 + j] = stickers[stkIdx].arr[c][r];
        }
    }

    return true;
}

bool upd4(int i, int j, int stkIdx, const pair<int, int>& stPoint)
{
    queue<pair<int, int>> stickerPoint;
    stickerPoint.push(stPoint);

    Sticker temp = stickers[stkIdx];
    //temp.arr[stPoint.first][stPoint.second] = -1;

    while (!stickerPoint.empty())
    {
        pair<int, int> p = stickerPoint.front();
        stickerPoint.pop();

        for (int k = 0; k < 5; ++k)
        {
            int x = p.second + nx[k];
            int y = p.first + ny[k];
            if (x < 0 || x >= stickers[stkIdx].row || y < 0 || y >= stickers[stkIdx].col)
                continue;
            if (temp.arr[y][x] == 0 || temp.arr[y][x] == -1)
                continue;
            if (y + j >= row || stickers[stkIdx].row - x - 1 + i >= col
                || note[stickers[stkIdx].row - x - 1 + i][y + j] == 1)
                return false;

            temp.arr[y][x] = -1;
            if (k != 0)
            {
                stickerPoint.push({ y, x });
            }
        }
    }

    int stk_row = stickers[stkIdx].row;
    int stk_col = stickers[stkIdx].col;

    for (int c = 0; c < stk_col; ++c)
    {
        for (int r = 0; r < stk_row; ++r)
        {
            if (stickers[stkIdx].arr[c][r] == 1)
                note[stickers[stkIdx].row - r - 1 + i][c + j] = stickers[stkIdx].arr[c][r];
        }
    }

    return true;
}

void check_sticker(int idx)
{
    int stk_row = stickers[idx].row;

    pair<int, int> stPoint{ 0, 0 };

    for (int i = 0; i < stk_row; ++i)
    {
        if (stickers[idx].arr[0][i] == 1)
        {
            stPoint.second = i;
            break;
        }
    }

    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            //if (note[i][j] == 0)
            //{
                if (upd1(i, j, idx, stPoint))
                    return;
            //}
        }
    }
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            //if (note[i][j] == 0)
            //{
                if (upd2(i, j, idx, stPoint))
                    return;
            //}
        }
    }
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            //if (note[i][j] == 0)
            //{
                if (upd3(i, j, idx, stPoint))
                    return;
            //}
        }
    }
    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            //if (note[i][j] == 0)
            //{
                if (upd4(i, j, idx, stPoint))
                    return;
            //}
        }
    }
}

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> col >> row >> stickerNum;

    stickers.reserve(stickerNum);

    for (int i = 0; i < stickerNum; ++i)
    {
        int stk_col, stk_row;
        cin >> stk_col >> stk_row;

        Sticker st1{};
        st1.arr.resize(stk_col);
        st1.row = stk_row;
        st1.col = stk_col;

        for (int j = 0; j < stk_col; ++j)
        {
            st1.arr[j].resize(stk_row);
            for (int k = 0; k < stk_row; ++k)
            {
                int stk_state;
                cin >> stk_state;
                st1.arr[j][k] = stk_state;
            }
        }
        stickers.push_back(move(st1));
    }

    for (int i = 0; i < stickers.size(); ++i)
    {
        check_sticker(i);
    }

    for (int i = 0; i < col; ++i)
    {
        for (int j = 0; j < row; ++j)
        {
            if (note[i][j] == 1)
                ++result;
        }
    }

    cout << result;

    return 0;
}