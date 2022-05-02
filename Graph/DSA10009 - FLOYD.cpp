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
    int n, m;
    cin >> n >> m;
    int F[n + 5][n + 5];
    int x, y, z;
    for(int i = 1; i <= n; ++i)
    {
        for(int j = 1; j <= n; ++j)
            F[i][j] = 1e9;
        F[i][i] = 0;
    }
    while(m--)
    {
        cin >> x >> y >> z;
        F[x][y] = F[y][x] = z;
    }
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            for(int z = 1; z <= n; ++z)
                F[j][z] = min(F[j][z], F[i][j] + F[i][z]);
    int t;
    cin >> t;
    while(t--)
    {
        cin >> x >> y;
        cout << F[x][y] << endl;
    }
    return 0;
}
