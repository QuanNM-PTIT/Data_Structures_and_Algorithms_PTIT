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

vector<vi> edge;
bitset<100005> visited;
vi trace;

void BFS(int u)
{
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(q.sz)
    {
        u = q.front();
        q.pop();
        for(int &i : edge[u])
        {
            if(!visited[i])
            {
                q.push(i);
                trace[i] = u;
                visited[i] = 1;
            }
        }
    }
}

void findPath(int s, int e)
{
    if(!trace[e])
    {
        cout << -1;
        return;
    }
    vi res;
    while(e != s)
    {
        if(!e)
        {
            cout << -1;
            return;
        }
        res.pb(e);
        e = trace[e];
    }
    res.pb(e);
    reverse(all(res));
    for(int &i : res) cout << i << ' ';
}

int main()
{
    faster();
    int t = 1, n, m, x, y, s, e;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> s >> e;
        edge.resize(n + 1);
        trace.resize(n + 1);
        for(int i = 1; i <= n; ++i)
        {
            edge[i].clear();
            trace[i] = 0;
            visited[i] = 0;
        }
        while(m--)
        {
            cin >> x >> y;
            edge[x].pb(y);
        }
        BFS(s);
        findPath(s, e);
        cout << endl;
    }
    return 0;
}