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
int trace[1005] = {};

inline void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(q.sz)
    {
        u = q.front();
        q.pop();
        for(int &i : a[u])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                q.push(i);
                trace[i] = u;
            }
        }
    }
}

inline void findPath(int st, int en)
{
    if(!visited[en])
    {
        cout << -1 << endl;
        return;
    }
    stack<int> path;
    path.push(en);
    while(trace[en])
    {
        en = trace[en];
        path.push(en);
    }
    while(path.sz)
    {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;
}

int main()
{
    faster();
    int t = 1, v, e, x, y, st, en;
    cin >> t;
    while(t--)
    {
        cin >> v >> e >> st >> en;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        BFS(st);
        findPath(st, en);
        for(int i = 1; i <= v; ++i)
        {
            a[i].clear();
            visited[i] = 0;
        }
    }
    return 0;
}

