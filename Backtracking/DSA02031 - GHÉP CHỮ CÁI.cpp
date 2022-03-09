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

bool check(char c)
{
    return (c == 'A' or c == 'E');
}

bool ok(string s)
{
    for(int i = 0; i < s.sz; ++i)
    {
        if(check(s[i]))
        {
            if(i == 0 or i == s.sz - 1) continue;
            if(!check(s[i - 1]) and !check(s[i + 1])) return 0;
        }
    }
    return 1;
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        string s = "ABC";
        char c;
        cin >> c;
        for(char j = 'D'; j <= c; ++j) s += j;
        do
        {
            if(ok(s)) cout << s << endl;
        }
        while(next_permutation(all(s)));
    }
    return 0;
}
