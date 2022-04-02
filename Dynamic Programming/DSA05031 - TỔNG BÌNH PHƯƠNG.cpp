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
    int t = 1, n, sqr;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int dp[10005] = {};
        for(int i = 1; i <= n; ++i)
        {
            dp[i] = INT_MAX;
            sqr = sqrt(i);
            for(int j = 1; j <= sqr; ++j)
                if(dp[i - j * j] < INT_MAX)
                    dp[i] = min(dp[i], dp[i - j * j] + 1);
        }
        cout << dp[n] << endl;
    }
    return 0;
}
