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
int u, v;

inline bool check(int x)
{
    bitset<105> visited;
    visited[x] = 1;
    queue<int> q;
    q.push(u);
    visited[u] = 1;
    while(q.sz)
    {
        x = q.front();
        q.pop();
        for(int &i : a[x])
        {
            if(!visited[i])
            {
                if(i == v)
                    return 1;
                q.push(i);
                visited[i] = 1;
            }
        }
    }
    return 0;
}

int main()
{
    faster();
    int t = 1, n, m, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m >> u >> v;
        while(m--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        int ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            if(i == u or i == v)
                continue;
            ans += !check(i);
        }
        cout << ans << endl;
        for(int i = 1; i <= n; ++i)
            a[i].clear();
    }
    return 0;
}

