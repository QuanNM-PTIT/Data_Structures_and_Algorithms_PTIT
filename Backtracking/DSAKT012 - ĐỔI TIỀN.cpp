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

int b[35], n, s;
bool flag;

void Try(int i, int cur = 0, int cnt = 0)
{
    if(flag) return;
    if(cur > s) return;
    if(cur == s)
    {
        flag = 1;
        cout << cnt << endl;
        return;
    }
    for(int j = i; j <= n; ++j) Try(j + 1, cur + b[j], cnt + 1);
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(int i = 1; i <= n; ++i) cin >> b[i];
        sort(b + 1, b + 1 + n, greater<ll>());
        flag = 0;
        Try(1);
        if(!flag) cout << -1 << endl;
    }
    return 0;
}
