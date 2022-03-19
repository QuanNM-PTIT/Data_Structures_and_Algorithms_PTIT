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

int root[1005];

inline int findRoot(int u)
{
    if(u == root[u])
        return u;
    root[u] = findRoot(root[u]);
    return root[u];
}

inline bool check(vector<pair<int, int>> &vp)
{
    int rootU, rootV;
    for(pair<int, int> &i : vp)
    {
        rootU = findRoot(i.fi);
        rootV = findRoot(i.se);
        if(rootU == rootV)
            return 1;
        root[rootU] = rootV;
    }
    return 0;
}

int main()
{
    faster();
    int t = 1, e, v, x, y;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        for(int i = 1; i <= v; ++i)
            root[i] = i;
        vector<pair<int, int>> vp;
        while(e--)
        {
            cin >> x >> y;
            vp.pb({x, y});
        }
        if(check(vp))
            cout << "YES" << endl;
        else
            cout << "NO" << endl;
    }
    return 0;
}