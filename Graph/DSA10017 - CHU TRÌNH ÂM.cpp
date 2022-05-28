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
int w[1005][1005];
bool check;

inline bool BFS(int u)
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
                q.push({i, top.se + w[top.fi][i]});
                visited[i] = 1;
            }
            else if(i == u and top.se + w[top.fi][i] < 0)
                return 1;
        }
    }
    return 0;
}

int main()
{
    faster();
    int t = 1, v, e, x, y, z;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y >> z;
            a[x].pb(y);
            w[x][y] = z;
        }
        check = 0;
        for(int i = 1; i <= v; ++i)
        {
            check = BFS(i);
            if(check)
                goto End;
            visited.reset();
        }
        End:
        cout << check << endl;
        for(int i = 1; i <= v; ++i)
            a[i].clear();
        visited.reset();
    }
    return 0;
}