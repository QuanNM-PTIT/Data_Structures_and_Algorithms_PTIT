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

int cnt, n, m;
int a[105][105];

void Try(int i, int j)
{
    if(i == n && j == m) ++cnt;
    if(i < n) Try(i + 1, j);
    if(j < m) Try(i, j + 1);
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        cnt = 0;
        Try(1, 1);
        cout << cnt << endl;
    }
    return 0;
}
