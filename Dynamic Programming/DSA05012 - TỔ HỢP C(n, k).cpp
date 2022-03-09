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

const ll int mod = 1e9 + 7;

inline ll calc(int n, int k)
{
    vector<ll int> invert(k + 5, 0);
    invert[0] = 1;
    if(k + 1 >= 2) invert[1] = 1;
    FOR(i, 2, k) invert[i] = mod - (mod / i) * invert[mod % i] % mod;
    int res = 1;
    FOR(i, 2, k) res = ((res % mod) * (invert[i] % mod)) % mod;
    ll ed = n - k + 1;
    FORD(i, n, ed) res = ((res % mod) * (i % mod)) % mod;
    return res;
}

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        cout << calc(n, k) << endl;
    }
    return 0;
}
