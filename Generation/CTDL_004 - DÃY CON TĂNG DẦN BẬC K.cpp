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

int n, k, a[105];
ll ans = 0;

void Try(int i, int cnt = 0)
{
    for(int j = i + 1; j <= n; ++j)
    {
        if(a[j] > a[i])
        {
            ++cnt;
            if(cnt == k) ++ans;
            Try(j, cnt);
            --cnt;
        }
    }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        Try(0);
        cout << ans;
    }
    return 0;
}
