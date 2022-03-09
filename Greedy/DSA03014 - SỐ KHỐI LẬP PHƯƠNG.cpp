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

vll v;

string calc(string &s)
{
    string tmp;
    for(ll &i : v)
    {
        tmp = to_string(i);
        int idx = 0;
        for(char &j : s) if(j == tmp[idx]) ++idx;
        if(idx == tmp.sz) return tmp;
    }
    return to_string(-1);
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    for(int i = 1e2; i; --i) v.pb(i * i * i);
    string s;
    while(t--)
    {
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}