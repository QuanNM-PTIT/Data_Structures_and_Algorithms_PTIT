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

vector<int> a[10005];
bitset<10005> visited;
int dis[10005] = {}, low[10005] = {}, par[10005] = {};
int cnt = 1, canhCau = 0;
set<int> dinhTru;

inline void DFS(int u)
{
    int child = 0;
    visited[u] = 1;
    dis[u] = low[u] = cnt++;
    for(int &i : a[u])
    {
        if(!visited[i])
        {
            ++child;
            par[i] = u;
            DFS(i);
            low[u] = min(low[u], low[i]);
            if(low[i] > dis[u])
                ++canhCau;
            if(low[i] >= dis[u] and par[u])
                dinhTru.insert(u);
        }
        else if(i != par[u])
            low[u] = min(low[u], dis[i]);
    }
    if(child > 1 and !par[u])
        dinhTru.insert(u);
}

int main()
{
    faster();
    int t = 1, v, e, x, y;
    //cin >> t;
    while(t--)
    {
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        for(int i = 1; i <= v; ++i)
            if(!visited[i])
                DFS(i);
        cout << dinhTru.sz << ' ' << canhCau;
    }
    return 0;
}

