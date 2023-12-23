#include <bits/stdc++.h>

using namespace std;

int num, len;

map<int, bool> check;

void back(vector<int>& data, int start)
{
    if (data.size() == len)
    {
        for_each(data.begin(), data.end(), [](int d) {
            cout << d << ' ';
         });
        cout << '\n';
        return;
    }
  

    for (auto& p : check)
    {
        if (p.second)
            continue;
        data.push_back(p.first);
        p.second = true;
        back(data, p.first);
        data.erase(data.end() - 1);
        p.second = false;
    }

}

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    cin >> num >> len;
    
    for (int i = 0; i <num; ++i)
    {
        int a;
        cin >> a;
        check.insert({a, false});
    }

    vector<int> data;

    back(data, 1);

    return 0;
}