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

int n, m;
int dx[] = {-1, 1, 0, 0};
int dy[] = {0, 0, 1, -1};
vector<string> vs;

inline bool check(int x, int y)
{
    return (x >= 0 and y >= 0 and x < n and y < m and vs[x][y] == '#');
}

void DFS(int x, int y)
{
    if(check(x, y))
    {
        vs[x][y] = '.';
        for(int i = 0; i < 4; ++i)
            DFS(x + dx[i], y + dy[i]);
    }
}

int main()
{
    faster();
    cin >> n >> m;
    string s;
    while(cin >> s)
        vs.pb(s);
    int res = 0;
    for(int i = 0; i < n; ++i)
    {
        for(int j = 0; j < m; ++j)
        {
            if(vs[i][j] == '#')
            {
                ++res;
                DFS(i, j);
            }
        }
    }
    cout << res;
    return 0;
}
