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

vector<pair<int, int>> x;
vector<vector<int> > f;
string res;
void trace(int n, int v)
{
    if (n == 0) return;
    if (f[n][v] == f[n - 1][v]) trace(n - 1, v);
    else
    {
        trace(n - 1, v - x[n].fi);
        res[n - 1] = '1';
    }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int v, n;
        cin >> n >> v;
        f.resize((n + 1), vector<int> (v + 1, 0));
        x.resize(n + 1);
        for(int i = 1; i <= n; i++)
        {
            res = res + "0";
            cin >> x[i].se;
        }
        for(int i = 1; i <= n; i++) cin >> x[i].fi;
        for(int i = 0; i <= n; i++) f[i][0] = 0;
        for(int i = 0; i <= v; i++) f[0][i] = 0;
        for(int i = 1; i <= n; i++)
            for(int j = 1; j <= v; j++)
            {
                if (j < x[i].fi) f[i][j] = f[i - 1][j];
                else f[i][j] = max(f[i - 1][j], f[i - 1][j - x[i].fi] + x[i].se);
            }
        cout << f[n][v] << endl;
        trace(n, v);
        for(char c: res) cout << c <<' ';
    }
    return 0;
}
