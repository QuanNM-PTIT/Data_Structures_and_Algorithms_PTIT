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

inline void DFS(int x, vector<vector<int>> &a, vector<int> &b)
{
    if(check) return;
    b[x] = 1;
    for(int &i : a[x])
    {
        if(!b[i]) DFS(i, a, b);
        else if(b[i] == 1)
        {
            check = 1;
            return;
        }
    }
    b[x] = 2;
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
        vector<int> b(v + 5, 0);
        check = 0;
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        for(int i = 1; i <= v; ++i)
        {
            if(check) break;
            else if(!b[i]) DFS(i, a, b);
        }
        if(check) cout << "YES" << endl;
        else cout << "NO" << endl;
    }
    return 0;
}
