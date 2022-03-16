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

string ans;
char sign[] = {'+', '-'};
bool ok;

bool check(string &s)
{
    int a = stoi(s.substr(0, 2)), b = stoi(s.substr(5, 2)), check;
    if (s[3] == '+') check = a + b;
    else check = a - b;
    string tmp = to_string(check);
    string c = s.substr(10, 2);
    return tmp == c;
}

void Try(int i, string s)
{
    if(ok) return;
    if(i == s.sz)
    {
        if(check(s))
        {
            ans = s;
            ok = 1;
        }
        return;
    }
    if(s[i] != '?')
    {
        if(!ok) Try(i + 1, s);
        return;
    }
    if(i == 3)
    {
        for (char j : sign)
        {
            s[i] = j;
            if(!ok) Try(i + 1, s);
        }
    }
    else if(!i or i == 5 or i == 10)
    {
        for (char j = '1'; j <= '9'; ++j)
        {
            s[i] = j;
            if(!ok) Try(i + 1, s);
        }
    }
    else
    {
        for(char j = '0'; j <= '9'; ++j)
        {
            s[i] = j;
            if(!ok) Try(i + 1, s);
        }
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    cin.ignore();
    while(t--)
    {
        ok = 0;
        ans = "";
        getline(cin, s);
        if (s[3] == '*' or s[3] == '/')
        {
            cout << "WRONG PROBLEM!\n";
            continue;
        }
        Try(0, s);
        if (ans.empty()) cout << "WRONG PROBLEM!\n";
        else cout << ans << endl;
    }
    return 0;
}