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

int lcs(string &s)
{
    int res = 1;
    int len = s.sz;
    int l, r;
    for(int i = 1; i < len; ++i)
    {
        l = i - 1;
        r = i;
        while(l >= 0 and r < len and s[l] == s[r])
        {
            --l;
            ++r;
        }
        ++l;
        --r;
        if(s[l] == s[r] and r - l + 1 > res) res = r - l + 1;
        l = i - 1;
        r = i + 1;
        while(l >= 0 and r < len and s[l] == s[r])
        {
            --l;
            ++r;
        }
        ++l;
        --r;
        if(s[l] == s[r] and r - l + 1 > res) res = r - l + 1;
    }
    return res;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        cout << lcs(s) << endl;
    }
    return 0;
}
