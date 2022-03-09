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
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int dp[41][41] = {};
        string tmp = s;
        reverse(tmp.begin(), tmp.end());
        for(int i = 0; i < s.sz; ++i)
        {
            for(int j = 0; j < tmp.sz; ++j)
            {
                if(s[i] == tmp[j]) dp[i + 1][j + 1] = dp[i][j] + 1;
                else dp[i + 1][j + 1] = max(dp[i + 1][j], dp[i][j + 1]);
            }
        }
        int M = dp[s.sz][tmp.sz];
        cout << s.sz - M << endl;
    }
    return 0;
}
