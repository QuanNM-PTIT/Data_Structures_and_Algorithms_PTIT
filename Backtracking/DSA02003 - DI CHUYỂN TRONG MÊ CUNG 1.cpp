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

bool a[25][25], check;
int n;
string s;
 
void Try(int i, int j)
{
    if(i == n && j == n)
    {
        cout << s << ' ';
        check = 1;
        return;
    }
    if(a[i+1][j])
    {
        s += 'D';
        Try(i + 1, j);
        s.erase(s.length() - 1, 1);
    }
    if(a[i][j+1])
    {
        s += 'R';
        Try(i, j + 1);
        s.erase(s.length() - 1, 1);
    }
}
 
int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        check = 0;
        cin >> n;
        FOR(i, 1, n) FOR(j, 1, n) cin >> a[i][j];
        if(!a[1][1]) cout << -1;
        else
        {
            Try(1, 1);
            if(!check) cout << -1;
        }
        cout << endl;
    }
    return 0;
}
