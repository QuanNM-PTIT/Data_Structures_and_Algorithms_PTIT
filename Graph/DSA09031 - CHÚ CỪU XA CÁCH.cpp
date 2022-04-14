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

int n, m, k;
vector<pair<pair<int, int>, pair<int, int>>> vp;
vector<pair<int, int>> a;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, -1, 1};
int f[105][105] = {};
int idx = 0;
int C[100005] = {};

inline bool check(int u, int v, int x, int y)
{
    if(x < 1 or x > n or y < 1 or y > n)
        return 0;
    if(f[x][y])
        return 0;
    for(pair<pair<int, int>, pair<int, int>> &i : vp)
        if((i.fi == mp(u, v) and i.se == mp(x, y)) or (i.fi == mp(x, y) and i.se == mp(u, v)))
            return 0;
    return 1;
}

inline void BFS(int x, int y)
{
    f[x][y] = idx;
    queue<pair<int, int>> q;
    pair<int, int> top;
    q.push({x, y});
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            if(check(top.fi, top.se, top.fi + dx[i], top.se + dy[i]))
            {
                f[top.fi + dx[i]][top.se + dy[i]] = idx;
                q.push({top.fi + dx[i], top.se + dy[i]});
            }
        }
    }
}

int main()
{
    faster();
    cin >> n >> k >> m;
    int u, v, x, y;
    vp.resize(m);
    a.resize(k);
    for(int i = 0; i < m; ++i)
    {
        cin >> u >> v >> x >> y;
        vp[i].fi = {u, v};
        vp[i].se = {x, y};
    }
    for(int i = 0; i < k; ++i)
    {
        cin >> x >> y;
        a[i] = {x, y};
    }
    ll res = 0;
    for(int i = 0; i < a.sz; ++i)
    {
        if(!f[a[i].fi][a[i].se])
        {
            ++idx;
            BFS(a[i].fi, a[i].se);
        }
    }
    ll cnt;
    for(pair<int, int> &i : a)
        ++C[f[i.fi][i.se]];
    for(int i = 1; i <= idx; ++i)
    {
        cnt = 0;
        for(int j = i + 1; j <= idx; ++j)
            cnt += C[j];
        res += C[i] * cnt;
    }
    cout << res;
    return 0;
}
