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

int n, m;
bitset<1005> visited;
vector<int> a[1005];

inline int BFS(int u, int v)
{
    queue<pair<int, int>> q;
    q.push({u, 0});
    visited[u] = 1;
    pair<int, int> top;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int &i : a[top.fi])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                if(i == v)
                    return top.se + 1;
                q.push({i, top.se + 1});
            }
        }
    }
    return -1;
}

int main()
{
    faster();
    int t = 1, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(m--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        double res = 0;
        int cnt = 0, val;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                if(i - j)
                {
                    val = BFS(i, j);
                    if(val != -1)
                    {
                        res += val;
                        ++cnt;
                    }
                    visited.reset();
                }
            }
        }
        cout << setprecision(2) << fixed << res / cnt << endl;
        for(int i = 1; i <= n; ++i)
            a[i].clear();
        visited.reset();
    }
    return 0;
}