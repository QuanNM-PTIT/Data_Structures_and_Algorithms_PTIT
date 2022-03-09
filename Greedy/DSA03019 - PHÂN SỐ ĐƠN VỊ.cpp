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

inline void solve(ll p, ll q)
{
    ll x = 0;
    while(1)
    {
        if(q % p == 0)
        {
            cout << "1/" << q / p << endl;
            return;
        }
        x = q / p + 1;
        cout << "1/" << x << " + ";
        p = x * p - q;
        q *= x;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    ll p, q;
    while(t--)
    {
        cin >> p >> q;
        solve(p, q);
    }
    return 0;
}