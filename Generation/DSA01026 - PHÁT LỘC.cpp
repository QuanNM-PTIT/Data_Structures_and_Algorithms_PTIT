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

string s;
int n;
char a[2] = {'6', '8'};

bool check()
{
    int cnt6 = 0, cnt8 = 0;
    for(char &i : s)
    {
        if(i == '6')
        {
            ++cnt6;
            cnt8 = 0;
        }
        else
        {
            ++cnt8;
            cnt6 = 0;
        }
        if(cnt6 > 3 or cnt8 > 1) return 0;
    }
    return 1;
}

void Try(int i)
{
    for(int j = 0; j < 2; ++j)
    {
        s[i] = a[j];
        if(i == n)
        {
            if(check()) cout << s << endl;
        }
        else Try(i + 1);
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
        s.resize(n);
        s[0] = '8';
        s.back() = '6';
        n -= 2;
        Try(1);
    }
    return 0;
}
