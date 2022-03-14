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

inline void DFS(int x, int par, vector<vector<int>> &a, bitset<1005> &bs)
{
    if(check) return;
    bs[x] = 1;
    for(int &i : a[x])
    {
        if(!bs[i]) DFS(i, x, a, bs);
        else if(bs[i] == 1 and i != par)
        {
            check = 1;
            return;
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
            else if(!bs[i]) DFS(i, 1, a, bs);
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}