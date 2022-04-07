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
    int t, n, k;
    cin >> t;
    int mod = 1e9 + 7;
    while(t--)
    {
        cin >> n >> k;
        int dp[100005] = {};
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= n; ++i)
        {
            for(int j = 1; j <= min(i, k); ++j)
            {
                dp[i] += dp[i - j];
                dp[i] %= mod;
            }
        }
        cout << dp[n] << endl;
    }
    return 0;
}
