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
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<ll, ll>> vp(n);
        for(pair<ll, ll> &i : vp)
            cin >> i.fi >> i.se;
        ll dp[n][2];
        dp[0][1] = vp[0].se;
        dp[0][0] = 0;
        for(int i = 1; i < n; ++i)
        {
            if(vp[i].fi == vp[i - 1].fi)
            {
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + vp[i].se;
                dp[i][0] = dp[i - 1][1];
            }
            else
            {
                dp[i][0] = min(dp[i - 1][0], dp[i - 1][1]);
                dp[i][1] = min(dp[i - 1][0], dp[i - 1][1]) + vp[i].se;
            }
        }
        cout << min(dp[n - 1][0], dp[n - 1][1]) << endl;
    }
    return 0;
}
