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
    int t = 1, n, insrt, cpy, del;
    cin >> t;
    while(t--)
    {
        cin >> n >> insrt >> del >> cpy;
        int dp[n + 1], i = 1;
        dp[0] = 0;
        while(i <= n)
        {
            dp[i] = dp[i - 1] + insrt;
            if(i & 1)
                dp[i] = min(dp[i], dp[(i + 1) >> 1] + del + cpy);
            else
                dp[i] = min(dp[i], dp[i / 2] + cpy);
            ++i;
        }
        cout << dp[n] << endl;
    }
    return 0;
}
