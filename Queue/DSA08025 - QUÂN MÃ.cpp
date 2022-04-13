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

int dx[] = {-2, -2, 2, 2, -1, -1, 1, 1};
int dy[] = {1, -1, -1, 1, 2, -2, -2, 2};

inline int BFS(pair<int, int> &st, pair<int, int> &en)
{
    int f[10][10] = {};
    pair<int, int> fr;
    queue<pair<int, int>> q;
    q.push(st);
    f[st.fi][st.se] = 1;
    while(q.sz)
    {
        fr = q.front();
        q.pop();
        for(int i = 0; i < 8; ++i)
        {
            if(fr.fi + dx[i] <= 8 and fr.fi + dx[i] >= 1 and fr.se + dy[i] <= 8 and fr.se + dy[i] >= 1 and !f[fr.fi + dx[i]][fr.se + dy[i]])
            {
                if(fr.fi + dx[i] == en.fi and fr.se + dy[i] == en.se)
                    return f[fr.fi][fr.se];
                f[fr.fi + dx[i]][fr.se + dy[i]] = f[fr.fi][fr.se] + 1;
                q.push({fr.fi + dx[i], fr.se + dy[i]});
            }
        }
    }
    return -1;
}

int main()
{
    faster();
    int t;
    string st, en;
    cin >> t;
    while(t--)
    {
        cin >> st >> en;
        pair<int, int> start, end;
        start = {st[0] - 'a' + 1, st[1] - '0'};
        end = {en[0] - 'a' + 1, en[1] - '0'};
        if(start == end)
            cout << 0 << endl;
        else
            cout << BFS(start, end) << endl;
    }
    return 0;
}
