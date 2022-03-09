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

unordered_map<ll, ll> F;
int mod = 1e9 + 7;

ll fibo(ll n)
{
    if(F[n]) return F[n];
    ll k = n >> 1;
    if(n & 1) return F[n] = (fibo(k) * fibo(k + 1) + fibo(k - 1) * fibo(k)) % mod;
    return F[n] = (fibo(k) * fibo(k) + fibo(k - 1) * fibo(k - 1)) % mod;
}

int main()
{
    faster();
    int t, n;
    F[0] = F[1] = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(!n) cout << 0 << endl;
        else cout << fibo(n - 1) << endl;
    }
    return 0;
}
