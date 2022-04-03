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

int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
int n, m;

vector<vector<int>> a(505, vector<int>(505));

inline bool check(int x, int y)
{
    return (x and y and x <= n and y <= m and a[x][y]);
}

inline void DFS(int x, int y)
{
    if(check(x, y))
    {
        a[x][y] = 0;
        for(int i = 0; i < 8; ++i)
            DFS(x + dx[i], y + dy[i]);
    }
}

int main()
{
    faster();
    int t = 1, ans;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= m; ++j)
                cin >> a[i][j];
        ans = 0;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 1; j <= m; ++j)
            {
                if(a[i][j])
                {
                    ++ans;
                    DFS(i, j);
                }
            }
        }
        cout << ans << endl;
    }
    return 0;
}
