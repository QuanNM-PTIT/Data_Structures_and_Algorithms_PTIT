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
    int t, n, k;
    cin >> t;
    const int mod = 1e9 + 7;
    int dp[105][50005] = {};
    for(int i = 1; i <= 9; ++i)
        dp[1][i] = 1;
    for(int i = 1; i <= 100; ++i)
        for(int j = 0; j <= 9; ++j)
            for(int z = j; z <= 50000; ++z)
                dp[i][z] = (dp[i][z] + dp[i - 1][z - j]) % mod;
    while(t--)
    {
        cin >> n >> k;
        cout << dp[n][k] << endl;
    }
    return 0;
}
