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

int n;
vector<char> v;
string res;

void Try(int i)
{
    for(int j = 'A'; j <= 'B'; ++j)
    {
        v.pb(j);
        if(i == n)
        {
            for(char &x : v)
                res += x;
            res += ',';
        }
        else
            if(v.sz < n)
                Try(i + 1);
        v.pop_back();
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        res = "";
        Try(1);
        res.pop_back();
        cout << res << endl;
    }
    return 0;
}
