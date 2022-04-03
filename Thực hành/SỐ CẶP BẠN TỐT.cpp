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
    const int nmax = 300005;
    int n, k, a[nmax], dp[nmax][25];
    string s;
    cin >> n >> k;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s;
        a[i] = s.sz;
    }
    for(int i = 1; i <= n; ++i) dp[i][0] = 0;
    for(int i = 1; i <= 20; ++i) dp[0][i] = 0;
    for(int j = 1; j <= 20; ++j)
      for(int i = 1; i <= n; ++i)
        if(a[i] == j)
            dp[i][j] = dp[i - 1][j] + 1;
        else
            dp[i][j] = dp[i - 1][j];
    ll res = 0;
    int tmp;
    for(int i = 1; i <= n; ++i)
    {
        tmp = 0;
        tmp = max(i - k - 1, tmp);
        res += dp[i][a[i]] - dp[tmp][a[i]] - 1;
    }
    cout << res;
    return 0;
}
