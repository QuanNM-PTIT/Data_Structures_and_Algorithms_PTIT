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

char t[7] = {};
bool dd[7] = {};
int x[7] = {}, n;
vector<string> v1, v2;

void printStr()
{
    string s = "";
    for(int i = 1; i <= n; ++i)
    {
        char tmp = (char) x[i] + 'A' - 1;
        s += tmp;
    }
    v1.pb(s);
}

void printInt()
{
    string s = "";
    for(int i = 1; i <= n; ++i)
        s += to_string(x[i]);
    v2.pb(s);
}

void TryInt(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        x[i] = j;
        if(i < n)
            TryInt(i + 1);
        else
            printInt();
    }
}

void TryStr(int i)
{
    for(int j = 1; j <= n; ++j)
    {
        if(!dd[j])
        {
            dd[j] = 1;
            x[i] = j;
            if(i < n)
                TryStr(i + 1);
            else
                printStr();
            dd[j] = 0;
        }
    }
}

int main()
{
    faster();
    cin >> n;
    TryInt(1);
    TryStr(1);
    for(string i : v1)
        for(string j : v2)
            cout << i + j << endl;
    return 0;
}
