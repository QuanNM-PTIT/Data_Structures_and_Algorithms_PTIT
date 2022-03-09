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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.fi < b.fi;
}

int main()
{
    faster();
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vector<pair<int, int>> vp(n);
        for(int i = 0; i < n; ++i)
        {
            cin >> vp[i].se;
            vp[i].fi = abs(vp[i].se - k);
        }
        stable_sort(all(vp), cmp);
        for(pair<int, int> i : vp) cout << i.se << ' ';
        cout << endl;
    }
    return 0;
}
