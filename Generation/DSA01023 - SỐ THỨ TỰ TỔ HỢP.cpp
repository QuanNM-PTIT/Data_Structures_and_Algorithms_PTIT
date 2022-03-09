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

int n, k;
bool f[20];
vi a, v;
int cnt = 0;
bool ok;

bool check()
{
    return a == v;
}

void Try(int i)
{
    if(ok) return;
    for(int j = v[i - 1] + 1; j <= n - k + i; ++j)
    {
        v[i] = j;
        if(i == k)
        {
            ++cnt;
            if(check())
            {
                ok = 1;
                return;
            }
        }
        else Try(i + 1);
        if(ok) return;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        ok = 0;
        cnt = 0;
        cin >> n >> k;
        a.resize(n + 1);
        v.resize(n + 1);
        memset(f, 0, 20);
        for(int i = 1; i <= k; ++i) cin >> a[i];
        Try(1);
        cout << cnt << endl;
    }
    return 0;
}