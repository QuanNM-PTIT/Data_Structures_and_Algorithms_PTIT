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

int main()
{
    faster();
    int n;
    string s;
    cin >> n >> s;
    ll total = (1LL * n * (n - 1)) >> 1;
    int cnt = 1;
    vi v;
    for(int i = 1; i < s.sz; ++i)
    {
        if(s[i] == s[i - 1])
            ++cnt;
        else
        {
            v.pb(cnt);
            cnt = 1;
        }
    }
    v.pb(cnt);
    for(int i = 1; i < v.sz; ++i)
        total -= (v[i] + v[i - 1] - 1);
    cout << total;
    return 0;
}
