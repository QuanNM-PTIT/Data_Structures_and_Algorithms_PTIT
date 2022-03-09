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

int a[20][20], n, res = INT_MAX;
bool dd[20] = {};

void Try(int i, int sum = 0, int cnt = 1)
{
    if(sum > res) return;
    if(cnt == n)
    {
        res = min(res, sum + a[i][1]);
        return;
    }
    for(int j = 1; j <= n; ++j)
    {
        if(!dd[j])
        {
            dd[j] = 1;
            Try(j, sum + a[i][j], cnt + 1);
            dd[j] = 0;
        }
    }
}

int main()
{
    faster();
    cin >> n;
    for(int i = 1; i <= n; ++i) for(int j = 1; j <= n; ++j) cin >> a[i][j];
    dd[1] = 1;
    Try(1);
    cout << res;
    return 0;
}
