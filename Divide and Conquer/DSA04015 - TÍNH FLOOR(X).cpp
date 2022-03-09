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
    int t = 1, n, idx;
    cin >> t;
    ll x;
    while(t--)
    {
        cin >> n >> x;
        vll v;
        v.resize(n);
        for(ll &i : v) cin >> i;
        idx = lower_bound(all(v), x) - v.begin();
        if(v[idx] != x) --idx;
        if(idx > 0) cout << idx + 1 << endl;
        else cout << -1 << endl;
    }
    return 0;
}
