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
    int t = 1, n, x, sum, k, mod = 1e9 + 7, dp[100005];
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        ++n;
        ++k;
        sum = 1;
        for(int i = 1; i < k; ++i)
        {
            dp[i] = sum;
            sum = (sum + dp[i]) % mod;
        }
        x = 1;
        sum -= 1;
        for(int i = k; i < n; ++i)
        {
            dp[i] = sum;
            sum -= dp[x++];
            sum += dp[i];
            sum %= mod;
            if(sum < 0) sum += mod;
        }
        cout << dp[n - 1] << endl;
    }
    return 0;
}