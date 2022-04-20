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

inline int BFS(vector<int> a[])
{
    bitset<100005> bs;
    int res = -1;
    queue<int> q;
    int f[100005] = {};
    int top;
    q.push(1);
    bs[1] = 1;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int &i : a[top])
        {
            if(!bs[i])
            {
                f[i] = f[top] + 1;
                res = max(res, f[i]);
                q.push(i);
            }
        }
    }
    return res;
}

int main()
{
    faster();
    int t, n, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n;
        --n;
        vector<int> a[n + 5];
        while(n--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        cout << BFS(a) << endl;
    }
    return 0;
}
