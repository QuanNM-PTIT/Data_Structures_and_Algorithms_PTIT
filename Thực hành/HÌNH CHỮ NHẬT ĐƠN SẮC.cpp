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

int main()
{
    faster();
    int n, m;
    cin >> n >> m;
    int a[m], b[m];
    for(int &i : a)
        cin >> i;
    for(int i = 0; i < m; ++i)
        b[i] = n - a[i];
    int l[m], r[m];
    stack<int> st1, st2, st3, st4;
    st1.push(m - 1);
    for(int i = m - 1; ~i; --i)
    {
        while(st1.sz and a[i] <= a[st1.top()])
            st1.pop();
        if(st1.sz)
            r[i] = st1.top() - 1;
        else
            r[i] = m - 1;
        st1.push(i);
    }
    for(int i = 0; i < m; ++i)
    {
        while(st2.sz and a[i] <= a[st2.top()])
            st2.pop();
        if(st2.sz)
            l[i] = st2.top() + 1;
        else
            l[i] = 0;
        st2.push(i);
    }
    ll res1 = 0, res2 = 0;
    for(int i = 0; i < m; ++i)
            res1 = max(res1, 1LL * a[i] * (r[i] - l[i] + 1));
    st3.push(m - 1);
    for(int i = m - 1; ~i; --i)
    {
        while(st3.sz and b[i] <= b[st3.top()])
            st3.pop();
        if(st3.sz)
            r[i] = st3.top() - 1;
        else
            r[i] = m - 1;
        st3.push(i);
    }
    for(int i = 0; i < m; ++i)
    {
        while(st4.sz and b[i] <= b[st4.top()])
            st4.pop();
        if(st4.sz)
            l[i] = st4.top() + 1;
        else
            l[i] = 0;
        st4.push(i);
    }
    for(int i = 0; i < m; ++i)
            res2 = max(res2, 1LL * b[i] * (r[i] - l[i] + 1));
    cout << max(res1, res2);
    return 0;
}

