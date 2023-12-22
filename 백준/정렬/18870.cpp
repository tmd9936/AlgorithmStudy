#include "bits/stdc++.h"
using namespace std;

int N;

vector<int> origin;
vector<int> D;
vector<int> newD;

int main(void) 
{
	ios::sync_with_stdio(0);
	cin.tie(0);
    
    origin.reserve(1000005);
    D.reserve(1000005);
    
    cin >> N;
    
    for (int i = 0; i < N; ++i)
    {
        int d;
        cin >> d;
        origin.push_back(d);
        D.push_back(d);
    }
    
    sort(D.begin(), D.end());
    
    for (int i = 0; i < N; ++i)
    {
        if (i == 0 || D[i-1] != D[i])
            newD.push_back(D[i]);
    }
    
    for (int i = 0; i < N; ++i)
    {
        cout << lower_bound(newD.begin(), newD.end(), origin[i]) - newD.begin() << " ";
    }
    
    return 0;
}