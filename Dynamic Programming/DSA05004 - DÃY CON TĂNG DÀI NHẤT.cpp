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
    int t = 1, n;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        vi a(n);
        for(int &i : a) cin >> i;
        int res = 1;
        vi dp(n, 0);
        for(int i = 0; i < n; ++i)
        {
            dp[i] = 1;
            for(int j = 0; j < i; ++j) if(a[j] < a[i]) dp[i] = max(dp[i], dp[j] + 1);
            res = max(res, dp[i]);
        }
        cout << res;
    }
    return 0;
}
