#include <bits/stdc++.h>
using namespace std;

int N;
vector<pair<int, int>> table;

int result = 0;

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int s, e;
        cin >> s >> e;
        table.push_back({s, e});
    }
    
    sort(table.begin(), table.end(), [](const pair<int, int>& p1, const pair<int, int>& p2) -> bool {
        if (p1.second != p2.second)
            return p1.second < p2.second;
        else
            return p1.first < p2.first;
    });
    
    int endTime = 0;
    for (int i = 0; i < N; ++i)
    {
        if (table[i].first >= endTime)
        {
            endTime = table[i].second;
            ++result;
        }
    }
    
    cout << result;
    
    return 0;
}