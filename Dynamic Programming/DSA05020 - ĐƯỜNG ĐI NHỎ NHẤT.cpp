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
    int t = 1, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<vi> a(n, vi (m));
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j) cin >> a[i][j];
        for(int i = 1; i < m; ++i) a[0][i] += a[0][i - 1];
        for(int i = 1; i < n; ++i)
            for(int j = 0; j < m; ++j)
            {
                int tmp = a[i - 1][j];
                if (j - 1 >= 0) tmp = min(tmp, (min(a[i - 1][j - 1], a[i][j - 1])));
                a[i][j] += tmp;
            }
        cout << a[n - 1][m - 1] << endl;
    }
    return 0;
}
