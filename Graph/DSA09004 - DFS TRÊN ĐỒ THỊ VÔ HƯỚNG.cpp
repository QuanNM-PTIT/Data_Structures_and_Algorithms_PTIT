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

vector<vi> edge(100005);
bitset<100005> visited;

void DFS(int u)
{
    visited[u] = 1;
    cout << u << ' ';
    for(int i = 0; i < edge[u].sz; ++i) if(!visited[edge[u][i]]) DFS(edge[u][i]);
}

int main()
{
    faster();
    int t = 1, n, m, x, y, u;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> u;
        for(int i = 1; i <= n; ++i)
        {
            edge[i].clear();
            visited[i] = 0;
        }
        while(m--)
        {
            cin >> x >> y;
            edge[x].pb(y);
            edge[y].pb(x);
        }
        DFS(u);
        cout << endl;
    }
    return 0;
}