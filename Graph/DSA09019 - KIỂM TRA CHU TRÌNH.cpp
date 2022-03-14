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

bool check;

inline void BFS(int x, int par, vector<vector<int>> &a, bitset<1005> &bs)
{
    queue<pair<int, int>> q;
    pair<int, int> u;
    q.push({x, par});
    bs[x] = 1;
    while(q.sz)
    {
        u = q.front();
        q.pop();
        for(int &i : a[u.fi])
        {
            if(!bs[i])
            {
                bs[i] = 1;
                q.push({i, u.fi});
            }
            else if(bs[i] and i != u.se)
            {
                check = 1;
                return;
            }
        }
    }
}

int main()
{
    faster();
    int t = 1, e, v, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        vector<vector<int>> a(v + 5);
        bitset<1005> bs;
        check = 0;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        for(int i = 1; i <= v; ++i)
        {
            if(check) break;
            else if(!bs[i]) BFS(i, 1, a, bs);
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}