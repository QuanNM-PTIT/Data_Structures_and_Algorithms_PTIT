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
    int t = 1, n, s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s;
        int a[n];
        for(int &i : a) cin >> i;
        bitset<40005> dp;
        dp[0] = 1;
        for(int i = 0; i < n; ++i)
            for(int j = s; j >= a[i]; --j)
                if(dp[j - a[i]])
                    dp[j] = 1;
        if(dp[s]) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
