// Created by Nguyễn Mạnh Quân
// Code WA

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

ll mod = 1e9 + 7;

inline ll Mul(ll a, ll b, ll MOD)
{
    a %= MOD;
    b %= MOD;
    long double tmp = a * b;
    ll x = tmp / MOD;
    return (a * b - x * MOD) % MOD;
}

inline ll binPow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = (Mul(res, a, mod)) % mod;
        a = (Mul(a, a, mod)) % mod;
        b >>= 1;
    }
    return res % mod;
}

int main()
{
    faster();
    int t;
    cin >> t;
    ll n, k;
    while(t--)
    {
        cin >> n >> k;
        vector<ll> v(k + 5);
        v[0] = 1;
        for(int i = 1; i <= k + 1; ++i)
            v[i] = (v[i - 1] + binPow(i + 1, k));
        if(n <= k + 2)
        {
            cout << v[n - 1] << endl;
            continue;
        }
        vector<ll> fact(k + 5), inv(k + 5);
        fact[0] = 1;
        for(int i = 1; i <= k + 1; ++i)
            fact[i] = Mul(fact[i - 1], i, mod);
        inv[k + 1] = binPow(fact[k + 1], mod - 2);
        for(ll i = k; ~i; --i)
            inv[i] = Mul(inv[i + 1], i + 1, mod);
        ll x = 1;
        for(int i = 1; i <= k + 2; ++i)
            x = Mul(x, n - i, mod);
        ll res = 0, tmp1, tmp2;
        for(int i =  1; i <= k + 2; ++i)
        {
            if(((k - i) & 1) ^ 1)
                tmp1 = v[i - 1];
            else
                tmp1 = -v[i - 1];
            if(tmp1 < 0)
                tmp1 += mod;
            tmp2 = x * binPow(n - i, mod - 2) % mod * Mul(inv[k + 2 - i], inv[i - 1], mod);
            res = (res + Mul(tmp1, tmp2, mod)) % mod;
        }
        cout << res << endl;
    }
    return 0;
}
