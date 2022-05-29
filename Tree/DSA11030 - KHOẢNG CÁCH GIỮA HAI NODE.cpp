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

vector<int> a[1005];
bitset<1005> visited;
int res;
bool check;

inline void DFS(int u, int v, int cnt = 0)
{
    if(check)
        return;
    visited[u] = 1;
    if(u == v)
    {
        check = 1;
        res = cnt;
        return;
    }
    for(int &i : a[u])
        if(!visited[i])
            DFS(i, v, cnt + 1);
}

int main()
{
    faster();
    int t = 1, n, q, u, v;
    cin >> t;
    while(t--)
    {
        cin >> n;
        while(--n)
        {
            cin >> u >> v;
            a[u].pb(v);
            a[v].pb(u);
        }
        cin >> q;
        while(q--)
        {
            cin >> u >> v;
            res = 0;
            check = 0;
            DFS(u, v);
            cout << res << endl;
            visited.reset();
        }
        for(int i = 0; i <= 1e3; ++i)
            a[i].clear();
    }
    return 0;
}
