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

int n, cx[35], x[35], f[35][35] = {}, res = 1e9;
string s[35];
int p[125] = {};

void Update()
{
    int tmp = 0;
    FOR(i, 2, n) tmp += f[x[i - 1]][x[i]];
    if(res > tmp) res = tmp;
}

int count(string a,string b)
{
    memset(p, 0, sizeof(p));
    for(int i = 0; i < a.sz; ++i) ++p[a[i]];
    for(int i = 0; i < b.sz; ++i) ++p[b[i]];
    int d = 0;
    for(int i = 'A'; i <= 'Z'; ++i) d += p[i] > 1;
    return d;
}

void Try(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        if (cx[j])
        {
            x[i] = j;
            cx[j] = 0;
            if (i == n) Update();
            else Try(i + 1);
            cx[j] = 1;
        }
    }
}

int main()
{
    faster();
    cin >> n;
    for(int i = 1; i <= n; ++i)
    {
        cin >> s[i];
        cx[i] = 1;
    }
    for(int i = 1; i <= n; ++i)
    {
        for(int j = i + 1; j <= n; ++j)
        {
            f[i][j] = count(s[i], s[j]);
            f[j][i] = f[i][j];
        }
    }
    Try(1);
    cout << res;
    return 0;
}
