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

int main()
{
    faster();
    int t = 1, x;
    cin >> t;
    vector<vector<int>> a(t + 1, vi(t + 1, 0));
    //while(t--)
    cin.ignore();
    string s;
    for(int i = 1; i <= t; ++i)
    {
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
        {
            x = stoi(s);
            a[x][i] = a[i][x] = 1;
        }
    }
    for(int i = 1; i <= t; ++i)
    {
        for(int j = 1; j <= t; ++j) cout << a[i][j] << ' ';
        cout << endl;
    }
    return 0;
}
