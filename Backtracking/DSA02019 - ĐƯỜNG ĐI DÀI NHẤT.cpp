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

int n, m, res = 0;
vector<vector<bool>> x;

void Try(int u, int sum = 0)
{
    res = max (res, sum);
    for(int v = 0; v < n; v++)
        if (x[u][v] == 1)
        {
            x[u][v] = x[v][u] = 0;
            Try(v, sum + 1);
            x[u][v] = x[v][u] = 1;
        }
}

int main()
{
    faster();
    int t = 1, a, b;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        x.resize(n + 5, vector<bool> (n + 5));
        res = 0;
        for(int i = 0; i < m; i++)
        {
            cin >> a >> b;
            x[a][b] = x[b][a] = 1;
        }
        for(int i = 1; i < n; i++) Try(i);
        cout << res << endl;
        x.clear();
    }
    return 0;
}
