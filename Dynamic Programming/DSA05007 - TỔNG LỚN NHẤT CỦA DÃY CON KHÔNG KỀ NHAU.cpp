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
    cin >> t;
    ll dp[1000005];
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        if(n == 1) cout << a[0] << endl;
        else if(n == 2) cout << max(a[0], a[1]) << endl;
        else
        {
            dp[0] = a[0];
            dp[1] = max(a[0], a[1]);
            for(int i = 2; i < n; ++i) dp[i] = max(dp[i - 1], dp[i - 2] + a[i]);
            cout << dp[n - 1] << endl;
        }
    }
    return 0;
}
