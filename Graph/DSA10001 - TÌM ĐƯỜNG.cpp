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

int n, m;
pair<int, int> s;
bool check;

inline void BFS(vector<string> &vs)
{
    if(vs[s.fi][s.se] == 'T')
    {
        check = 1;
        return;
    }
    int f[505][505] = {}, idx, up = 0, down = n - 1, left = 0, right = m - 1;
    pair<int, int> u, v;
    queue<pair<int, int>> q;
    q.push(s);
    while(q.sz)
    {
        u = q.front();
        q.pop();
        if(f[u.fi][u.se] > 2) return;
        idx = u.fi;
        while(idx > up)
        {
            v.fi = idx - 1;
            v.se = u.se;
            if(vs[v.fi][v.se] == '*') break;
            else if(vs[v.fi][v.se] == 'T')
            {
                check = 1;
                return;
            }
            else if(!f[v.fi][v.se])
            {
                f[v.fi][v.se] = f[u.fi][u.se] + 1;
                q.push(v);
            }
            --idx;
        }
        idx = u.fi;
        while(idx < down)
        {
            v.fi = idx + 1;
            v.se = u.se;
            if(vs[v.fi][v.se] == '*') break;
            else if(vs[v.fi][v.se] == 'T')
            {
                check = 1;
                return;
            }
            else if(!f[v.fi][v.se])
            {
                f[v.fi][v.se] = f[u.fi][u.se] + 1;
                q.push(v);
            }
            ++idx;
        }
        idx = u.se;
        while(idx > left)
        {
            v.fi = u.fi;
            v.se = idx - 1;
            if(vs[v.fi][v.se] == '*') break;
            else if(vs[v.fi][v.se] == 'T')
            {
                check = 1;
                return;
            }
            else if(!f[v.fi][v.se])
            {
                f[v.fi][v.se] = f[u.fi][u.se] + 1;
                q.push(v);
            }
            --idx;
        }
        idx = u.se;
        while(idx < right)
        {
            v.fi = u.fi;
            v.se = idx + 1;
            if(vs[v.fi][v.se] == '*') break;
            else if(vs[v.fi][v.se] == 'T')
            {
                check = 1;
                return;
            }
            else if(!f[v.fi][v.se])
            {
                f[v.fi][v.se] = f[u.fi][u.se] + 1;
                q.push(v);
            }
            ++idx;
        }
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        cin.ignore();
        vector<string> vs(n);
        for(int i = 0; i < n; ++i) getline(cin, vs[i]);
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                if(vs[i][j] == 'S') s = {i, j};
        check = 0;
        BFS(vs);
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}