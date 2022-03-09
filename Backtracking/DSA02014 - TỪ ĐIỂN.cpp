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

vector<string> res;
set<string> dic;
vector<bitset<10>> f;
vector<vector<string>> a;
int k, n, m;
int dx[] = {-1, -1, -1, 0, 0, 1, 1, 1};
int dy[] = {-1, 0, 1, -1, 1, -1, 0, 1};
string tmp;

void DFS(int i, int j, string s)
{
    if(dic.find(s) != dic.end()) res.pb(s);
    for(int x = 0; x < 8; ++x)
    {
        int u = i + dx[x];
        int v = j + dy[x];
        if (u >= 0 and u < n and v >= 0 and v < m and !f[u][v])
        {
            f[u][v] = 1;
            DFS(u, v, s + a[u][v]);
            f[u][v] = 0;
        }
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> k >> n >> m;
        a.resize(n, vector<string> (m));
        for(int i = 0; i < k; ++i)
        {
            cin >> tmp;
            dic.insert(tmp);
        }
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
                cin >> a[i][j];
        for(int i = 0; i < n; i++)
            for(int j = 0; j < m; j++)
            {
                f.clear();
                f.resize(n);
                f[i][j] = 1;
                DFS(i, j, "" + a[i][j]);
            }
        if(res.empty()) cout << -1;
        else for(string &s : res) cout << s << ' ';
        cout << endl;
        dic.clear();
        res.clear();
        a.clear();
    }
    return 0;
}
