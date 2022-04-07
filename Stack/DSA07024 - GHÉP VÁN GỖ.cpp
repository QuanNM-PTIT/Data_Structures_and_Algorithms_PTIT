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
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n];
        for(ll &i : a) cin >> i;
        stack<int> st1, st2;
        int l[n], r[n];
        st1.push(n - 1);
        for(int i = n - 1; ~i; --i)
        {
            while(st1.sz and a[i] <= a[st1.top()]) st1.pop();
            if(st1.sz) r[i] = st1.top() - 1;
            else r[i] = n - 1;
            st1.push(i);
        }
        for(int i = 0; i < n; ++i)
        {
            while(st2.sz and a[i] <= a[st2.top()]) st2.pop();
            if(st2.sz) l[i] = st2.top() + 1;
            else l[i] = 0;
            st2.push(i);
        }
        ll res = 0;
        for(int i = 0; i < n; ++i)
            if(r[i] - l[i] + 1 >= a[i])
                res = max(res, a[i]);
        cout << res << endl;
    }
    return 0;
}
