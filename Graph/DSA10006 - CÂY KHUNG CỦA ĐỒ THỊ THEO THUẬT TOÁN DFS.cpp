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
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

inline void DFS(int x, vector<vector<int>> &a, bitset<1005> &bs, vector<pair<int, int>> &vp)
{
    bs[x] = 1;
    for(int &i : a[x])
    {
        if(!bs[i])
        {
            vp.pb({x, i});
            DFS(i, a, bs, vp);
        }
    }
}

int main()
{
    faster();
    int t = 1, e, v, u, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e >> u;
        vector<vector<int>> a(v + 5);
        bitset<1005> bs;
        vector<pair<int, int>> res;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        DFS(u, a, bs, res);
        if(res.sz == v - 1)
            for(pair<int, int> &i : res)
                cout << i.fi << ' ' << i.se << endl;
        else cout << -1 << endl;
    }
    return 0;
}
