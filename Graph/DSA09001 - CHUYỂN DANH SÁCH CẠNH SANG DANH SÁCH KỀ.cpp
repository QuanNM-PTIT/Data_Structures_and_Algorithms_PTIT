// Created by Nguyễn Mạnh Quân

#include<bits/stdc++.h>

using namespace std;

#define mp make_pair
#define fi first
#define se second
#define pb push_back
#define sz size()
#define ll long long
#define FOR(i, a, b) for(int i = a; i <= b; i++)
#define FORD(i, a, b) for(int i = a; i >= b; i--)
#define F(i, a, b) for(int i = a; i < b; ++i)
#define FD(i, a, b) for(int i = a; i > b; --i)
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
    faster();
    int t = 1, v, e, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        vector<set<int>> vs(v + 1);
        while(e--)
        {
            cin >> x >> y;
            vs[x].insert(y);
            vs[y].insert(x);
        }
        for(int i = 1; i <= v; ++i)
        {
            cout << i << ": ";
            if(vs[i].empty()) continue;
            for(auto &j : vs[i]) cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}
