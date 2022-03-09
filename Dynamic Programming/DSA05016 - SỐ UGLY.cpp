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
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL); cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'

int main()
{
    faster();
    vi a;
    priority_queue<int, vi, greater<int>> pq;
    unordered_map<int, bool> m;
    pq.push(1);
    int tmp;
    while(a.sz < 1e4)
    {
        tmp = pq.top();
        pq.pop();
        a.pb(tmp);
        if(!m[tmp << 1])
        {
            pq.push(tmp << 1);
            m[tmp << 1] = 1;
        }
        if(!m[tmp * 3])
        {
            pq.push(tmp * 3);
            m[tmp * 3] = 1;
        }
        if(!m[tmp * 5])
        {
            pq.push(tmp * 5);
            m[tmp * 5] = 1;
        }
    }
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << a[n - 1] << endl;
    }
    return 0;
}
