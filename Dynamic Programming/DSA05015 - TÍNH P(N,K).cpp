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
    int t = 1, n, k, mod = 1e9 + 7;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        if(k > n)
            cout << 0 << endl;
        else if(!k)
            cout << 1 << endl;
        else
        {
            ll res = 1;
            for(int i = n - k + 1; i <= n; ++i)
                res = (res * i) % mod;
            cout << res << endl;
        }
    }
    return 0;
}