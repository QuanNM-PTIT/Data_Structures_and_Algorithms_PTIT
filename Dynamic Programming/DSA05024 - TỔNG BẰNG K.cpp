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
    int a[1005];
    int mod = 1e9 + 7;
    while(t--)
    {
        cin >> n >> k;
        vector<int> dp(k + 5, 0);
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        dp[0] = 1;
        for(int i = 1; i <= k; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                if(i >= a[j])
                    dp[i] = (dp[i] % mod + dp[i - a[j]] % mod) % mod;
            }
        }
        cout << dp[k] << endl;
    }
    return 0;
}
