#include <bits/stdc++.h>
using namespace std;

int nums[2000001];

int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    
    int n;
    cin >> n;
    
    for (int i = 0; i < n; ++i)
    {
        int num;
        cin >> num;
        nums[num + 1000000]++;
    }
    
    
    for (int i = 0; i < 2000001; ++i)
    {
        while (nums[i]--)
        {
            cout << i - 1000000 << '\n';
        }
    }
    
    return 0;
}