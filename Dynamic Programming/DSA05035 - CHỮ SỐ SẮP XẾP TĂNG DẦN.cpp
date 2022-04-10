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
    vll a(15, 1);
    ll dp[105] = {};
    const int mod = 1e9 + 7;
    dp[1] = 10;
    ll sum;
    for(int i = 2; i <= 100; ++i)
    {
        for(int j = 1; j < 10; ++j)
        {
            sum = 0;
            for(int z = j; z < 10; ++z)
                sum += a[z];
            dp[i] += sum;
            while(dp[i] >= mod)
                dp[i] -= mod;
            a[j] = sum;
        }
    }
    for(int i = 2; i <= 100; ++i)
    {
        dp[i] += dp[i - 1];
        while(dp[i] >= mod)
            dp[i] -= mod;
    }
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << dp[n] << endl;
    }
    return 0;
}