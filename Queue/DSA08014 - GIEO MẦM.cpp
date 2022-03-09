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

int a[505][505];
int n, m;

inline int BFS()
{
    int f[505][505] = {}, cnt1 = 0;
    queue<pair<int, int>> q;
    pair<int, int> p;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= m; ++j)
        {
            cnt1 += a[i][j] == 1;
            if(a[i][j] == 2)
            {
                q.push({i, j});
                f[i][j] = 1;
            }
        }
    }
    if(!cnt1) return 0;
    while(q.sz)
    {
        p = q.front();
        q.pop();
        if(p.fi - 1 >= 1 and a[p.fi - 1][p.se] == 1)
        {
            a[p.fi - 1][p.se] = 2;
            --cnt1;
            if(!cnt1) return f[p.fi][p.se];
            f[p.fi - 1][p.se] = f[p.fi][p.se] + 1;
            q.push({p.fi - 1, p.se});
        }
        if(p.fi + 1 <= n and a[p.fi + 1][p.se] == 1)
        {
            a[p.fi + 1][p.se] = 2;
            --cnt1;
            if(!cnt1) return f[p.fi][p.se];
            f[p.fi + 1][p.se] = f[p.fi][p.se] + 1;
            q.push({p.fi + 1, p.se});
        }
        if(p.se - 1 >= 1 and a[p.fi][p.se - 1] == 1)
        {
            a[p.fi][p.se - 1] = 2;
            --cnt1;
            if(!cnt1) return f[p.fi][p.se];
            f[p.fi][p.se - 1] = f[p.fi][p.se] + 1;
            q.push({p.fi, p.se - 1});
        }
        if(p.se + 1 <= m and a[p.fi][p.se + 1] == 1)
        {
            a[p.fi][p.se + 1] = 2;
            --cnt1;
            if(!cnt1) return f[p.fi][p.se];
            f[p.fi][p.se + 1] = f[p.fi][p.se] + 1;
            q.push({p.fi, p.se + 1});
        }
    }
    return -1;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        cout << BFS() << endl;
    }
    return 0;
}