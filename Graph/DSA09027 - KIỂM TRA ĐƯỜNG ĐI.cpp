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

vector<vi> edge;
bitset<100005> visited;
vi trace;

void DFS(int u)
{
    if(visited[u]) return;
    visited[u] = 1;
    for(int &i : edge[u])
    {
        if(!visited[i])
        {
            trace[i] = u;
            DFS(i);
        }
    }
}

int main()
{
    faster();
    int t = 1, n, m, x, y, s, e, q;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        edge.resize(n + 1);
        trace.resize(n + 1);
        for(int i = 1; i <= n; ++i)
        {
            edge[i].clear();
            trace[i] = 0;
            visited[i] = 0;
        }
        while(m--)
        {
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        cin >> q;
        while(q--)
        {
            cin >> s >> e;
            for(int i = 1; i <= n; ++i)
            {
                visited[i] = 0;
                trace[i] = 0;
            }
            DFS(s);
            if(visited[e]) cout << "YES\n";
            else cout << "NO\n";
        }
    }
    return 0;
}