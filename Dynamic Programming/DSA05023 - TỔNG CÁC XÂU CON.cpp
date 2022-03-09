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

ll sum = 0;
char x[15];
string s;
int k;

void print(int i)
{
    ll tmp = 0;
    for(int j = k; j <= i; ++j) tmp = tmp * 10 + x[j] - '0';
    sum += tmp;
}

void Try(int i)
{
    for(int j = i - 1; j < s.sz; ++j)
    {
        x[i] = s[j];
        print(i);
        Try(i + 1);
        j = s.sz - 1;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        sum = 0;
        cin >> s;
        for(k = 1; k <= s.sz; ++k) Try(k);
        cout << sum << endl;
    }
    return 0;
}
