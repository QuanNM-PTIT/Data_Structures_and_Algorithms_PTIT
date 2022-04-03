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
int a[25];
vector<int> v;
vector<string> res;

void Try(int i)
{
    if(v.sz > 1)
    {
        string s = "";
        for(int &i : v)
            s += to_string(i) + ' ';
        res.pb(s);
    }
    for(int j = i; j < n; ++j)
    {
        if(v.empty() or a[j] > v.back())
        {
            v.pb(a[j]);
            Try(j + 1);
            v.pop_back();
        }
    }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        Try(0);
        sort(all(res));
        for(string &i : res)
            cout << i << endl;
    }
    return 0;
}
