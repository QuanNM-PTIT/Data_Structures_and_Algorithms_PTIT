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
int a[505][505];

int dx[] = {0, 0, -1, 1};
int dy[] = {-1, 1, 0, 0};

struct cmp
{
    bool operator () (pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
    {
        return a.se.se > b.se.se;
    }
};

inline int BFS()
{
    int visited[505][505] = {};
    priority_queue<pair<int, pair<int, int>>, vector<pair<int, pair<int, int>>>, cmp> pq;
    pair<int, pair<int, int>> top;
    pq.push({1, {1, a[1][1]}});
    visited[1][1] = 1;
    int x, y;
    while(pq.sz)
    {
        top = pq.top();
        pq.pop();
        for(int i = 0; i < 4; ++i)
        {
            x = top.fi + dx[i];
            y = top.se.fi + dy[i];
            if(x == n and y == m)
                return top.se.se + a[x][y];
            if(x >= 1 and x <= n and y >= 1 and y <= m and !visited[x][y])
            {
                visited[x][y] = 1;
                pq.push({x, {y, top.se.se + a[x][y]}});
            }
        }
    }
    return -1;
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
        cout << BFS() << endl;
    }
    return 0;
}