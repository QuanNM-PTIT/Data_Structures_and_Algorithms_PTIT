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

vector<int> a[105];
bitset<105> visited;

inline void DFS(int u)
{
    visited[u] = 1;
    for(int &i : a[u])
        if(!visited[i])
            DFS(i);
}

int main()
{
    faster();
    int t = 1, v, e, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        int k = 0;
        for(int i = 1; i <= v; ++i)
        {
            if(!visited[i])
            {
                ++k;
                DFS(i);
            }
        }
        int res = 1e9;
        for(int i = 1; i <= v; ++i)
        {
            int cnt = 0;
            visited.reset();
            visited[i] = 1;
            for(int j = 1; j <= v; ++j)
            {
                if(!visited[j])
                {
                    ++cnt;
                    DFS(j);
                }
            }
            if(cnt > k)
            {
                res = i;
                k = cnt;
            }
        }
        if(res == 1e9)
            cout << 0 << endl;
        else
            cout << res << endl;
        for(int i = 1; i <= v; ++i)
            a[i].clear();
        visited.reset();
    }
    return 0;
}

