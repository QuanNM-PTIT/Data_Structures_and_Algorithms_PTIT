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

int main()
{
    faster();
    int t = 1, n, m;
    cin >> t;
    int p[105], q[105];
    while(t--)
    {
        cin >> n >> m;
        vector<int> res(n + m, 0);
        for(int i = 0; i < n; ++i) cin >> p[i];
        for(int i = 0; i < m; ++i) cin >> q[i];
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                res[i + j] += p[i] * q[j];
        m += n - 1;
        for(int i = 0; i < m; ++i) cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}