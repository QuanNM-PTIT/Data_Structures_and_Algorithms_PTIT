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

inline string solve(ll* a, int &n, ll &k)
{
    unordered_map<ll, int> m;
    ll sum = 0;
    for(int i = 0; i < n; ++i)
    {
        sum += a[i];
        if(sum == k or m[sum - k])
            return "YES";
        m[sum] = 1;
    }
    return "NO";
}

int main()
{
    faster();
    int t, n;
    ll k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ll a[n];
        for(ll &i : a)
            cin >> i;
        cout << solve(a, n, k) << endl;
    }
    return 0;
}
