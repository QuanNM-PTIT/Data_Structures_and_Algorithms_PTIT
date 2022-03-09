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

int check(string &s)
{
    int f[130] = {};
    int MAX = 0;
    F(i, 0, s.length())
    {
        ++f[s[i]];
        MAX = max(f[s[i]], MAX);
    }
    if (MAX <= s.length() - MAX + 1) return 1;
    return -1;
}

int main()
{
    faster();
    int t = 1;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        cout << check(s) << endl;
    }
    return 0;
}