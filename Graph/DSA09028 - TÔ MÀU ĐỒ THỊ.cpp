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

inline bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.fi > b.fi;
}

inline bool check(int v, int e, int m)
{
    int dd[15][15] = {};
    int cnt[15] = {};
    int x, y;
    while(e--)
    {
        cin >> x >> y;
        cnt[x] += dd[x][y] == 0;
        cnt[y] += dd[y][x] == 0;
        dd[x][y] = dd[y][x] = 1;
    }
    vector<pair<int, int>> vp;
    for(int i = 1; i <= v; ++i)
        vp.pb({cnt[i], i});
    sort(all(vp), cmp);
    bitset<15> bs;
    int u, c = 0;
    for(pair<int, int> &i : vp)
    {
        u = i.se;
        if(!bs[u])
        {
            bs[u] = 1;
            ++c;
            // Tô các đỉnh không kề với u cùng màu với u
            for(int j = 1; j <= v; ++j)
                if(!dd[u][j])
                    bs[j] = 1;
        }
    }
    return c <= m;
}

int main()
{
    faster();
    int t, v, e, m;
    cin >> t;
    while(t--)
    {
        cin >> v >> e >> m;
        if(check(v, e, m))
            cout << "YES\n";
        else
            cout << "NO\n";
    }
    return 0;
}