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
    int t = 1, tmp;
    cin >> t;
    vector<vector<int>> v(t + 1);
    cin.ignore();
    string s;
//    while(t--)
    for(int i = 1; i <= t; ++i)
    {
        getline(cin, s);
        stringstream ss(s);
        while(ss >> s)
        {
            tmp = stoi(s);
            v[i].pb(tmp);
        }
    }
    for(int i = 1; i <= t; ++i)
    {
        sort(all(v[i]));
        for(int &j : v[i]) if(j > i) cout << i << ' ' << j << endl;
    }
    return 0;
}
