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

int mod = 123456789;

inline ll calc(ll n)
{
    if(n == 1) return 1;
    long long x = calc(n >> 1) % mod;
    if(n & 1) return (((x * x % mod) << 2) % mod) % mod;
    return (((x * x % mod) << 1) % mod) % mod;
}

int main()
{
    faster();
    int t = 1;
    ll n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << calc(n) << endl;
    }
    return 0;
}
