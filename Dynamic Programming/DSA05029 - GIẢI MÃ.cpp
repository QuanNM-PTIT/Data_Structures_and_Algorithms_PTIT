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
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        if(s[0] == '0')
        {
            cout << 0 << endl;
            continue;
        }
        int dp[1005] = {};
        dp[0] = dp[1] = 1;
        for(int i = 2; i <= s.sz; ++i)
        {
            if(s[i - 1] > '0') dp[i] = dp[i - 1];
            if(s[i - 2] == '1' or (s[i - 2] == '2' && s[i - 1] < '7')) dp[i] += dp[i - 2];
        }
        cout << dp[s.sz] << endl;
    }
    return 0;
}
