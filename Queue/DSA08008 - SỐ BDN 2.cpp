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

ll n;

bool check(string &s)
{
    ll tmp = 0;
    for(char &i : s)
    {
        tmp = tmp * 10 + i - '0';
        tmp %= n;
    }
    return !tmp;
}

string findNum()
{
    queue<string> q;
    q.push("1");
    string s;
    while(q.sz)
    {
        s = q.front();
        q.pop();
        if(check(s)) return s;
        q.push(s + "0");
        q.push(s + "1");
    }
    return "";
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << findNum() << endl;
    }
    return 0;
}