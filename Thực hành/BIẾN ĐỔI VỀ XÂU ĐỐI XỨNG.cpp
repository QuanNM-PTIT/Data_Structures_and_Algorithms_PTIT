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
    int t;
    cin >> t;
    string s, s1, s2;
    while(t--)
    {
        cin >> s2;
        s1 = s2;
        reverse(all(s2));
        vector<vector<int>> dp(105, vector<int>(105, 0));
        for(int i = 0; i < s1.sz; ++i)
        {
            for(int j = 0; j < s2.sz; ++j)
            {
                if(s1[i] == s2[j])
                    dp[i + 1][j + 1] = dp[i][j] + 1;
                else
                    dp[i + 1][j + 1] = max(dp[i][j + 1], dp[i + 1][j]);
            }
        }
        cout << s1.sz - dp[s1.sz][s2.sz] << endl;
    }
    return 0;
}
