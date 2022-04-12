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

int dp[105][8105];

int Find(int a, int b)
{
    if(a > 100 or b > 8100 or a > b or a < 0 or b < 0)
        return -1;
    if(!a and !b)
        return 0;
    if(dp[a][b] != -1)
        return dp[a][b];
    int res = 105, i = 9;
    while(i)
    {
        int tmp = Find(a - i, b - i * i);
        if(tmp != -1)
            res = min(res, tmp + 1);
        --i;
    }
    dp[a][b] = res;
    return res;
}

int main()
{
    faster();
    int t, a, b;
    cin >> t;
    while(t--)
    {
        memset(dp, -1, sizeof(dp));
        dp[0][0] = 0;
        cin >> a >> b;
        int MIN = Find(a, b);
        if(MIN == -1 or MIN > 100)
            cout << -1;
        else
        {
            int i;
            while(a > 0 and b > 0)
            {
                i = 1;
                while(i < 10)
                {
                    if(a >= i and b >= i * i and dp[a - i][b - i * i] + 1 == dp[a][b])
                    {
                        cout << i;
                        a -= i;
                        b -= i * i;
                        break;
                    }
                    ++i;
                }
            }
        }
        cout << endl;
    }
    return 0;
}
