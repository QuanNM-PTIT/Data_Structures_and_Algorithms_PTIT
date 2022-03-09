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

string s = "2000";
char a[2] = {'0', '2'};
vector<string> d, m, y;

void Try(int i)
{
    for(int j = 0; j < 2; ++j)
    {
        s[i] = a[j];
        if(i == 3) y.pb(s);
        else Try(i + 1);
    }
}

int main()
{
    faster();
    d.pb("02");
    d.pb("20");
    d.pb("22");
    m.pb("02");
    Try(1);
    for(string &i : d) for(string &j : y) cout << i << "/02/" << j << endl;
    return 0;
}

