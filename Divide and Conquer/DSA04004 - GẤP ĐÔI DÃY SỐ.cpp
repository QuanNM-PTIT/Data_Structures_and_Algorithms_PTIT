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

inline ll binPow(ll a, ll b)
{
    if(!b) return 1;
    ll res = binPow(2, b >> 1);
    res = res * res;
    if(b & 1) res = res << 1;
    return res;
}

inline ll findNum(ll n, ll k)
{
    ll x = binPow(2, n - 1);
    if(k == x) return n;
    if(k < x) return findNum(n - 1, k);
    return findNum(n - 1, k - x);
}

int main()
{
    faster();
    int t = 1;
    ll n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << findNum(n, k) << endl;
    }
    return 0;
}

// Cách 2:

// #include <stdio.h>

// int main()
// {
//     int t, n;
//     long long k, cnt;
//     scanf("%d", &t);
//     while(t--)
//     {
//         scanf("%d", &n);
//         scanf("%lld", &k);
//         cnt = 0;
//         while((k & 1) ^ 1)
//         {
//             ++cnt;
//             k >>= 1;
//         }
//         printf("%lld\n", cnt + 1);
//     }
//     return 0;
// }
