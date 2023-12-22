#include <iostream>
#include <vector>

using namespace std;

int N, M;

bool dirIssue[4] = { false, false, false, false };

struct CamInfo
{
    int x;
    int y;
    int num;
};

vector<vector<int>> room;
vector<vector<int>> issue;

vector<CamInfo> camIdx;

int min_room = 10000;

void issueAllFalse()
{
    dirIssue[0] = false;
    dirIssue[1] = false;
    dirIssue[2] = false;
    dirIssue[3] = false;
}

void issueAllTrue()
{
    dirIssue[0] = true;
    dirIssue[1] = true;
    dirIssue[2] = true;
    dirIssue[3] = true;
}

int draw_room(const CamInfo& info, int camNum)
{
    int cnt = 0;
    if (dirIssue[0])
    {
        for (int i = info.y - 1; i >= 0; --i)
        {
            if (room[info.x][i] == 6)
                break;
            if (room[info.x][i] >= 1 && room[info.x][i] <= 5)
                continue;
            if (issue[info.x][i] == -1)
            {
                issue[info.x][i] = camNum;
                ++cnt;
            }
        }
    }

    if (dirIssue[1])
    {
        for (int i = info.y + 1; i < M; ++i)
        {
            if (room[info.x][i] == 6)
                break;
            if (room[info.x][i] >= 1 && room[info.x][i] <= 5)
                continue;
            if (issue[info.x][i] == -1)
            {
                issue[info.x][i] = camNum;
                ++cnt;
            }
        }
    }

    if (dirIssue[2])
    {
        for (int i = info.x - 1; i >= 0; --i)
        {
            if (room[i][info.y] == 6)
                break;
            if (room[i][info.y] >= 1 && room[i][info.y] <= 5)
                continue;
            if (issue[i][info.y] == -1)
            {
                issue[i][info.y] = camNum;
                ++cnt;
            }
        }
    }

    if (dirIssue[3])
    {
        for (int i = info.x + 1; i < N; ++i)
        {
            if (room[i][info.y] == 6)
                break;
            if (room[i][info.y] >= 1 && room[i][info.y] <= 5)
                continue;
            if (issue[i][info.y] == -1)
            {
                issue[i][info.y] = camNum;
                ++cnt;
            }
        }
    }

    return cnt;
}

void back_room(const CamInfo& info, int camNum)
{
    if (dirIssue[0])
    {
        for (int i = info.y - 1; i >= 0; --i)
        {
            if (room[info.x][i] == 6)
                break;
            if (room[info.x][i] >= 1 && room[info.x][i] <= 5)
                continue;
            if (issue[info.x][i] == camNum)
            {
                issue[info.x][i] = -1;
            }
        }
    }

    if (dirIssue[1])
    {
        for (int i = info.y + 1; i < M; ++i)
        {
            if (room[info.x][i] == 6)
                break;
            if (room[info.x][i] >= 1 && room[info.x][i] <= 5)
                continue;
            if (issue[info.x][i] == camNum)
            {
                issue[info.x][i] = -1;
            }
        }
    }

    if (dirIssue[2])
    {
        for (int i = info.x - 1; i >= 0; --i)
        {
            if (room[i][info.y] == 6)
                break;
            if (room[i][info.y] >= 1 && room[i][info.y] <= 5)
                continue;
            if (issue[i][info.y] == camNum)
            {
                issue[i][info.y] = -1;
            }
        }
    }

    if (dirIssue[3])
    {
        for (int i = info.x + 1; i < N; ++i)
        {
            if (room[i][info.y] == 6)
                break;
            if (room[i][info.y] >= 1 && room[i][info.y] <= 5)
                continue;
            if (issue[i][info.y] == camNum)
            {
                issue[i][info.y] = -1;
            }
        }
    }
}

void room_check(const int& cnt)
{
    min_room = min(min_room, cnt);
}

void back(int idx, int cnt)
{
    if (idx == camIdx.size())
    {
        //cout << cnt << endl;
        room_check(cnt);
        return;
    }

    if (camIdx[idx].num == 1)
    {
        for (int i = 0; i < 4; ++i)
        {
            issueAllFalse();
            dirIssue[i] = true;
            back(idx + 1, cnt - draw_room(camIdx[idx], idx));
            issueAllFalse();
            dirIssue[i] = true;
            back_room(camIdx[idx], idx);
        }
    }
    else if (camIdx[idx].num == 2)
    {

        for (int i = 0; i < 2; ++i)
        {
            issueAllFalse();
            if (i == 0)
            {
                dirIssue[0] = true;
                dirIssue[1] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[0] = true;
                dirIssue[1] = true;
                back_room(camIdx[idx], idx);
            }
            else
            {
                dirIssue[2] = true;
                dirIssue[3] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[2] = true;
                dirIssue[3] = true;
                back_room(camIdx[idx], idx);
            }
        }
    }
    else if (camIdx[idx].num == 3)
    {
        for (int i = 0; i < 4; ++i)
        {
            issueAllFalse();
            if (i == 0)
            {
                dirIssue[2] = true;
                dirIssue[1] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[2] = true;
                dirIssue[1] = true;
                back_room(camIdx[idx], idx);
            }
            else if (i == 1)
            {
                dirIssue[3] = true;
                dirIssue[1] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[3] = true;
                dirIssue[1] = true;
                back_room(camIdx[idx], idx);
            }
            else if (i == 2)
            {
                dirIssue[3] = true;
                dirIssue[0] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[3] = true;
                dirIssue[0] = true;
                back_room(camIdx[idx], idx);
            }
            else
            {
                dirIssue[2] = true;
                dirIssue[0] = true;
                back(idx + 1, cnt - draw_room(camIdx[idx], idx));
                issueAllFalse();
                dirIssue[2] = true;
                dirIssue[0] = true;
                back_room(camIdx[idx], idx);
            }
        }
    }
    else if (camIdx[idx].num == 4)
    {
        for (int i = 0; i < 4; ++i)
        {
            issueAllTrue();
            dirIssue[i] = false;
            back(idx + 1, cnt - draw_room(camIdx[idx], idx));
            issueAllTrue();
            dirIssue[i] = false;
            back_room(camIdx[idx], idx);
        }
    }
    else if (camIdx[idx].num == 5)
    {
        issueAllTrue();
        back(idx + 1, cnt - draw_room(camIdx[idx], idx));
        issueAllTrue();
        back_room(camIdx[idx], idx);
    }
}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    
     cin >> N >> M;

    room.resize(N);
    issue.resize(N);

    for (int i = 0; i < N; ++i)
    {
        room[i].resize(M, 0);
        issue[i].resize(M, -1);

        for (int j = 0; j < M; ++j)
        {
            int a;
            cin >> a;
            room[i][j] = a;

            if (a >= 1 && a <= 5)
                camIdx.push_back({ i, j, a });
        }
    }

    int cnt = N * M;

    for (int i = 0; i < N; ++i)
    {
        for (int j = 0; j < M; ++j)
        {
            if (room[i][j] >= 1 && room[i][j] <= 5 || room[i][j] == 6)
            {
                --cnt;
            }

        }
    }

    back(0, cnt);

    cout << min_room;

    return 0;
}