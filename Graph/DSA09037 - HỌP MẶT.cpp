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

int k, v, e;
vector<int> a[1005];
bitset<1005> bs;
vector<int> vk;

inline void DFS(int u)
{
    bs[u] = 1;
    for(int &i : a[u])
        if(!bs[i])
            DFS(i);
}

inline bool check(int x)
{
    bs.reset();
    DFS(x);
    for(int &i : vk)
        if(!bs[i])
            return 0;
    return 1;
}

int main()
{
    faster();
    cin >> k >> v >> e;
    int x, y;
    while(k--)
    {
        cin >> x;
        vk.pb(x);
    }
    while(e--)
    {
        cin >> x >> y;
        a[x].pb(y);
    }
    int cnt = 0;
    for(int i = 1; i <= v; ++i)
        cnt += check(i);
    cout << cnt;
    return 0;
}