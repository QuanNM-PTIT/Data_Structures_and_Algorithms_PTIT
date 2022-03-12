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
    int t = 1, n, m, k;
    cin >> t;
    string a, b, c;
    while(t--)
    {
        cin >> n >> m >> k;
        cin >> a >> b >> c;
        int dp[n + 5][m + 5][k + 5];
        memset(dp, 0, sizeof(dp));
        for(int i = 1; i <= a.sz; ++i)
        {
            for(int j = 1; j <= b.sz; ++j)
            {
                for(int z = 1; z <= c.sz; ++z)
                {
                    if(a[i - 1] == b[j - 1] and a[i - 1] == c[z - 1]) dp[i][j][z] = dp[i - 1][j - 1][z - 1] + 1;
                    else dp[i][j][z] = max(dp[i - 1][j][z], max(dp[i][j - 1][z], dp[i][j][z - 1]));
                }
            }
        }
        cout << dp[n][m][k] << endl;
    }
    return 0;
}

