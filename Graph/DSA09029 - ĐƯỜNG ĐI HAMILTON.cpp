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

bitset<15> bs;
vector<int> a[15];
bool ok;

void DFS(int u, int v, int cnt = 1)
{
    if(cnt == v)
    {
        ok = 1;
        return;
    }
    if(ok)
        return;
    for(int &i : a[u])
    {
        if(!bs[i])
        {
            bs[i] = 1;
            DFS(i, v, cnt + 1);
            bs[i] = 0;
        }
    }
}

inline bool check(int v)
{
    for(int i = 1; i <= v; ++i)
    {
        bs.reset();
        bs[i] = 1;
        DFS(i, v);
        if(ok)
            return ok;
    }
    return 0;
}

int main()
{
    faster();
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for(int i = 0; i < 15; ++i)
            a[i].clear();
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        ok = 0;
        cout << check(v) << endl;
    }
    return 0;
}
