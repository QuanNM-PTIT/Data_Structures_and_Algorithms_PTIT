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

int main()
{
    faster();
    vector<vector<string>> res(15);
    res[1].pb("0");
    res[1].pb("1");
    for(int i = 2; i <= 10; ++i)
    {
        for(int j = 0; j < res[i - 1].sz; ++j) res[i].pb('0' + res[i - 1][j]);
        for(int j = res[i - 1].sz - 1; j >= 0 ; --j) res[i].pb('1' + res[i - 1][j]);
    }
    int t = 1;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        int idx = 0;
        for(int i = s.sz - 1; i >= 0; --i) if(s[i] == '1') idx += 1 << (s.sz - i - 1);
        cout << res[s.sz][idx] << endl;
    }
    return 0;
}

