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

inline int BFS(int a, int b)
{
    if(a > b) return a - b;
    int f[20005] = {};
    queue<int> q;
    q.push(a);
    int tmp;
    while(q.sz)
    {
        tmp = q.front();
        q.pop();
        if(tmp == b) return f[tmp];
        if((tmp << 1) < (b << 1) and !f[tmp << 1])
        {
            f[tmp << 1] = f[tmp] + 1;
            q.push(tmp << 1);
        }
        if(!f[tmp - 1])
        {
            f[tmp - 1] = f[tmp] + 1;
            q.push(tmp - 1);
        }
    }
    return -1;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        int a, b;
        cin >> a >> b;
        cout << BFS(a, b) << endl;
    }
    return 0;
}