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

int a, b, c;
int f[35][35][35] = {};
char hcn[35][35][35];
pair<pair<int, int>, int> S, E;
int x[] = {1, -1, 0, 0, 0, 0};
int y[] = {0, 0, 1, -1, 0, 0};
int z[] = {0, 0, 0, 0, 1, -1};

inline bool check(int i, int j, int k)
{
    return (i >= 0 and i < a and j >= 0 and j < b and k >= 0 and k < c and hcn[i][j][k] != '#' and !f[i][j][k]);
}

inline int BFS()
{
    queue<pair<pair<int, int>, int>> q;
    q.push(S);
    f[S.fi.fi][S.fi.se][S.se] = 1;
    pair<pair<int, int>, int> top;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int i = 0; i < 6; ++i)
        {
            if(check(top.fi.fi + x[i], top.fi.se + y[i], top.se + z[i]))
            {
                if(top.fi.fi + x[i] == E.fi.fi and top.fi.se + y[i] == E.fi.se and top.se + z[i] == E.se)
                    return f[top.fi.fi][top.fi.se][top.se];
                q.push({{top.fi.fi + x[i], top.fi.se + y[i]}, top.se + z[i]});
                f[top.fi.fi + x[i]][top.fi.se + y[i]][top.se + z[i]] = f[top.fi.fi][top.fi.se][top.se] + 1;
            }
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
        cin >> a >> b >> c;
        for(int i = 0; i < a; ++i)
        {
            for(int j = 0; j < b; ++j)
            {
                for(int z = 0; z < c; ++z)
                {
                    cin >> hcn[i][j][z];
                    if(hcn[i][j][z] == 'S')
                        S = {{i, j}, z};
                    else if(hcn[i][j][z] == 'E')
                        E = {{i, j}, z};
                }
            }
        }
        cout << BFS() << endl;
        memset(f, 0, sizeof(f));
    }
    return 0;
}
