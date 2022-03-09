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

int k;
char n;

void Try(int i, string s = "", char c = 'A')
{
    if(i == k)
    {
        cout << s << endl;
        return;
    }
    for(char j = c; j <= n; ++j) Try(i + 1, s + j, j);
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        Try(0);
    }
    return 0;
}
