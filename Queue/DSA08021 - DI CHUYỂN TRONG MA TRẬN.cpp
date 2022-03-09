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

int n, m, a[1005][1005];

inline int BFS()
{
    int M[1005][1005] = {};
    queue<pair<int, int>> q;
    pair<int, int> p;
    q.push({1, 1});
    M[1][1] = 0;
    while(q.sz)
    {
        p = q.front();
        q.pop();
        if(p.fi + a[p.fi][p.se] <= n and !M[p.fi + a[p.fi][p.se]][p.se])
        {
            if(p.fi + a[p.fi][p.se] == n and p.se == m) return M[p.fi][p.se] + 1;
            M[p.fi + a[p.fi][p.se]][p.se] = M[p.fi][p.se] + 1;
            q.push({p.fi + a[p.fi][p.se], p.se});
        }
        if(p.se + a[p.fi][p.se] <= m and !M[p.fi][p.se + a[p.fi][p.se]])
        {
            if(p.fi == n and p.se + a[p.fi][p.se] == m) return M[p.fi][p.se] + 1;
            M[p.fi][p.se + a[p.fi][p.se]] = M[p.fi][p.se] + 1;
            q.push({p.fi, p.se + a[p.fi][p.se]});
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