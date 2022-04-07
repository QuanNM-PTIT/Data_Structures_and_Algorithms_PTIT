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
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        vector<bitset<1005>> dp(s.sz + 5);
        int res = 1;
        dp[s.sz - 1][s.sz - 1] = 1;
        for(int i = 0; i < s.sz - 1; ++i)
        {
            dp[i][i] = 1;
            if(s[i] == s[i + 1])
            {
                dp[i][i + 1] = 1;
                res = 2;
            }
        }
        int z;
        for(int i = 3; i <= s.sz; ++i)
        {
            for(int j = 0; j < s.sz - i + 1; ++j)
            {
                z = i + j - 1;
                if(s[j] == s[z] and dp[j + 1][z - 1])
                {
                    dp[j][z] = 1;
                    res = max(res, i);
                }
            }
        }
        cout << res << endl;
    }
    return 0;
}
