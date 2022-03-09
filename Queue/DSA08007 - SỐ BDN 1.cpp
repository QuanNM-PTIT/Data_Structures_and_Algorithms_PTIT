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
    vll v;
    ll int tmp = 1;
    v.pb(tmp);
    while(tmp * 10 <= 1e17)
    {
        int s = v.sz;
        tmp *= 10;
        v.pb(tmp);
        for(int i = 0; i < s; ++i) v.pb(tmp + v[i]);
    }
    int t = 1;
    ll n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << upper_bound(all(v), n) - v.begin() << endl;
    }
    return 0;
}