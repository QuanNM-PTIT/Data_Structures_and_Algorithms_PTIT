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

int mod = 1e9 + 7;

ll binPow(ll a, ll b)
{
    if(!b) return 1;
    ll res = binPow(a, b >> 1);
    res = (res * res) % mod;
    if(b & 1) res = (res * a) % mod;
    return res;
}

int main()
{
    faster();
    ll a, b;
    while(1)
    {
        cin >> a >> b;
        if(!a and !b) return 0;
        cout << binPow(a, b) << endl;
    }
    return 0;
}
