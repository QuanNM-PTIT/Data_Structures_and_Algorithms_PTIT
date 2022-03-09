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

inline ll rev(ll n)
{
    ll res = 0;
    while(n)
    {
        res = res * 10 + n % 10;
        n /= 10;
    }
    return res;
}

const ll mod = 1e9 + 7;

inline ll binPow(ll n, ll p)
{
    if(p == 1) return n;
    ll res = binPow(n, p >> 1) % mod;
    res = (res * res) % mod;
    if(p & 1) res = (res * n) % mod;
    return res % mod;
}

int main()
{
    faster();
    int t = 1;
    ll n, p;
    cin >> t;
    while(t--)
    {
        cin >> n >> p;
        cout << binPow(n, p) << endl;
    }
    return 0;
}
