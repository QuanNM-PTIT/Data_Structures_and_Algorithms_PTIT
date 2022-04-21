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

string solve(int v, int e)
{
    int x, y;
    vector<int> a[v + 5];
    while(e--)
    {
        cin >> x >> y;
        a[x].pb(y);
        a[y].pb(x);
    }
    for(int i = 1; i <= v; ++i)
    {
        for(int &j : a[i])
            if(a[i].sz != a[j].sz)
                return "NO";
    }
    return "YES";
}

int main()
{
    faster();
    int t, v, e;
    cin >> t;
    while(t--)
    {
        cin >> v >> e;
        cout << solve(v, e) << endl;
    }
    return 0;
}
