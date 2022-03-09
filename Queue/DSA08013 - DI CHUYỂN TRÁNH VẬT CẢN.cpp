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

char a[105][105];
int n, startX, startY, endX, endY;

int BFS()
{
    int f[105][105] = {}, tmpX, tmpY;
    queue<pair<int, int>> q;
    pair<int, int> p;
    f[startX][startY] = 1;
    q.push({startX, startY});
    while(q.sz)
    {
        p = q.front();
        q.pop();
        if(p.fi == endX and p.se == endY) return f[p.fi][p.se];
        tmpX = p.fi + 1;
        while(tmpX <= n)
        {
            if(!f[tmpX][p.se] and a[tmpX][p.se] == '.')
            {
                if(tmpX == endX and p.se == endY) return f[p.fi][p.se];
                f[tmpX][p.se] = f[p.fi][p.se] + 1;
                q.push({tmpX, p.se});
            }
            else break;
            ++tmpX;
        }
        tmpX = p.fi - 1;
        while(tmpX >= 1)
        {
            if(!f[tmpX][p.se] and a[tmpX][p.se] == '.')
            {
                if(tmpX == endX and p.se == endY) return f[p.fi][p.se];
                f[tmpX][p.se] = f[p.fi][p.se] + 1;
                q.push({tmpX, p.se});
            }
            else break;
            --tmpX;
        }
        tmpY = p.se + 1;
        while(tmpY <= n)
        {
            if(!f[p.fi][tmpY] and a[p.fi][tmpY] == '.')
            {
                if(p.fi == endX and tmpY == endY) return f[p.fi][p.se];
                f[p.fi][tmpY] = f[p.fi][p.se] + 1;
                q.push({p.fi, tmpY});
            }
            else break;
            ++tmpY;
        }
        tmpY = p.se - 1;
        while(tmpY >= 1)
        {
            if(!f[p.fi][tmpY] and a[p.fi][tmpY] == '.')
            {
                if(p.fi == endX and tmpY == endY) return f[p.fi][p.se];
                f[p.fi][tmpY] = f[p.fi][p.se] + 1;
                q.push({p.fi, tmpY});
            }
            else break;
            --tmpY;
        }
    }
    return -1;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i)
            for(int j = 1; j <= n; ++j)
                cin >> a[i][j];
        cin >> startX >> startY >> endX >> endY;
        ++startX;
        ++startY;
        ++endX;
        ++endY;
        if(startX == endX and startY == endY) cout << 0 << endl;
        else cout << BFS() << endl;
    }
    return 0;
}
