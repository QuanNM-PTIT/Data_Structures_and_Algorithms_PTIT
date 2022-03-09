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

inline int m(string &s)
{
    int res = 0;
    for(char &i : s)
    {
        if(i == '6') i = '5';
        res = res * 10 + i - '0';
    }
    return res;
}

inline int M(string &s)
{
    int res = 0;
    for(char &i : s)
    {
        if(i == '5') i = '6';
        res = res * 10 + i - '0';
    }
    return res;
}

int main()
{
    faster();
    int t = 1;
    string a, b;
    //cin >> t;
    while(t--)
    {
        cin >> a >> b;
        cout << m(a) + m(b) << ' ' << M(a) + M(b) << endl;
    }
    return 0;
}
