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

inline void BFS(int x, vector<vector<int>> &a, bitset<1005> &bs, bool &check)
{
    queue<int> q;
    int u;
    q.push(x);
    bs[x] = 1;
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
            else
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
    bool check;
    while(t--)
    {
        bitset<1005> bs;
        cin >> v;
        e = v - 1;
        vector<vector<int>> a(v + 5);
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        for(int i = 1; i <= v; ++i)
        {
            check = 0;
            if(!bs[i])
                BFS(i, a, bs, check);
            if(check)
            {
                cout << "NO" << endl;
                break;
            }
        }
        if(!check) cout << "YES" << endl;
    }
    return 0;
}
