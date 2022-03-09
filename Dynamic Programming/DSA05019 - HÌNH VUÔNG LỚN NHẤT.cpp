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

bool a[505][505];
int dp[505][505];

int main()
{
    faster();
    int t = 1, n, m, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                cin >> a[i][j];
                dp[i][j] = a[i][j];
                if(dp[i][j]) ans = 1;
            }
        }
        for(int i = 0; i <= n; ++i) dp[0][i] = 0;
        for(int i = 0; i <= m; ++i) dp[i][0] = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(a[i][j])
                {
                    if(!a[i - 1][j] or !a[i][j - 1] or !a[i - 1][j - 1]) continue;
                    dp[i][j] = min(dp[i - 1][j], min(dp[i - 1][j - 1], dp[i][j - 1]));
                    ++dp[i][j];
                    ans = max(ans, dp[i][j]);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
