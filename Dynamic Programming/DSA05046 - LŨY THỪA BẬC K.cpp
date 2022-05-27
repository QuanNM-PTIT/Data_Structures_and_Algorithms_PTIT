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

const int mod = 1e9 + 7;
ll a[1005], b[1005], dp[1005];

ll Mul(ll a, ll b, ll m)
{
    a %= m;
    b %= m;
    ll tmp = (double) a * b / m;
    return (a * b - tmp * m);
}

ll Pow(ll a, ll b)
{
    ll res = 1;
    while(b)
    {
        if(b & 1)
            res = Mul(res, a, mod);
        a = Mul(a, a, mod);
        b >>= 1;
    }
    return res;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    ll n, k;
    while(t--)
    {
        cin >> n >> k;
        ll res = 0;
        a[0] = b[k + 3] = dp[0] = 1;
        ll tmp = k + 2;
        for(int i = 1; i <= tmp; ++i)
        {
            a[i] = Mul(a[i - 1], n - i, mod);
            b[tmp - i + 1] = Mul(b[tmp - i + 2], n - (tmp - i + 1), mod);
            dp[i] = Mul(dp[i - 1], i, mod);
        }
        ll sum = 0, x, y, z;
        for(int i = 1; i <= tmp; ++i)
        {
            sum += Pow(i, k);
            sum %= mod;
            x = Mul(sum, a[i - 1], mod);
            y = Mul(dp[i - 1], dp[k + 2 - i], mod);
            z = Mul(b[i + 1], Pow(Mul(y, ((k - i) & 1) ? -1 : 1, mod), mod - 2), mod);
            res = (res + Mul(x, z, mod)) % mod;
        }
        cout << (res + mod) % mod << endl;
    }
    return 0;
}