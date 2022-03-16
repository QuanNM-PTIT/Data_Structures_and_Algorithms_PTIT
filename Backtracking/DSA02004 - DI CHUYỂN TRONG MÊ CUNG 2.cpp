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

int n;
bool a[100][100];
bool check[100][100];
vector<string> res;

void Try(int i, int j, string s = "")
{
    if(!a[1][1] or !a[n][n]) return;
    if(i == n && j == n)
    {
        res.pb(s);
        return;
    }
    if(a[i + 1][j] and i != n and !check[i + 1][j])
    {
        check[i][j] = 1;
        Try(i + 1, j, s + "D");
        check[i][j] = 0;
    }
    if(a[i][j - 1] and j != 1 and !check[i][j - 1])
    {
        check[i][j] = 1;
        Try(i, j - 1, s + "L");
        check[i][j] = 0;
    }
    if(a[i][j + 1] and j != n and !check[i][j + 1])
    {
        check[i][j] = 1;
        Try(i, j + 1, s + "R");
        check[i][j] = 0;
    }
    if(a[i - 1][j] and i != 1 and !check[i - 1][j])
    {
        check[i][j] = 1;
        Try(i - 1, j, s + "U");
        check[i][j] = 0;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        res.clear();
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                check[i][j] = 0;
            }
        }
        Try(1, 1);
        if(res.empty()) cout << -1 << endl;
        else
        {
            for(string &i : res) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}

