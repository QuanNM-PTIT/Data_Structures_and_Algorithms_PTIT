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

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[n];
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            a[i] %= k;
        }
        int dp[n][k];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < k; ++j)
                dp[i][j] = INT_MIN;
        dp[0][a[0]] = 1;
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < k; ++j)
                dp[i][j] = max(dp[i - 1][j], dp[i - 1][(j + k - a[i]) % k] + 1);
        cout << dp[n - 1][0] << endl;
    }
    return 0;
}