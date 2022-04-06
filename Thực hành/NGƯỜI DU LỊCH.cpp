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

int n, MIN = INT_MAX;
int a[20][20];
bitset<20> bs;
vector<int> res, v;

void Try(int i, int sum = 0, int cnt = 1)
{
    if(sum > MIN)
        return;
    if(cnt == n)
    {
        if(MIN > sum + a[i][1])
        {
            MIN = sum + a[i][1];
            res = v;
        }
        return;
    }
    for(int j = 2; j <= n; ++j)
    {
        if(!bs[j])
        {
            bs[j] = 1;
            v[cnt] = j;
            Try(j, sum + a[i][j], cnt + 1);
            bs[j] = 0;
        }
    }
}

int main()
{
    faster();
    cin >> n;
    for(int i = 1; i <= n; ++i)
        for(int j = 1; j <= n; ++j)
            cin >> a[i][j];
    res.resize(n + 5);
    v.resize(n + 5);
    res[n] = v[n] = 1;
    bs[1] = 1;
    Try(1);
    cout << "(1,";
    for(int i = 1; i < n; ++i)
        cout << res[i] << ",";
    cout << res[n] << ")\n";
    cout << MIN;
    return 0;
}
