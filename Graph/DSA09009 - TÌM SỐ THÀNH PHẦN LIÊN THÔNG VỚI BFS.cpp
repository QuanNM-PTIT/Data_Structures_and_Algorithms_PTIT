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

vector<vi> a(1005);
bitset<1005> bs;

inline void BFS(int x)
{
    queue<int> q;
    q.push(x);
    bs[x] = 1;
    int u;
    while(q.sz)
    {
        u = q.front();
        q.pop();
        for(int &i : a[u])
        {
            if(!bs[i])
            {
                bs[i] = 1;
                q.push(i);
            }
        }
    }
}
  
int main()
{
    faster();
    int t = 1, v, e, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for(int i = 1; i <= v; ++i)
        {
            a[i].clear();
            bs[i] = 0;
        }
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        int cnt = 0;
        for(int i = 1; i <= v; ++i)
        {
            if(!bs[i])
            {
                ++cnt;
                BFS(i);
            }
        }
        cout << cnt << endl;
    }
    return 0;
}

