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
    if(a.se > b.se) return 1;
    else if(a.se < b.se) return 0;
    if(a.fi < b.fi) return 1;
    return 0;
}

int main()
{
    faster();
    int t = 1, n, m, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int, int>> vp;
        vi v;
        int dd[1000006] = {};
        FOR(i, 1, n)
        {
            cin >> x;
            if(!dd[x]) v.pb(x);
            ++dd[x];
        }
        for(int i : v) vp.pb(mp(i, dd[i]));
        sort(vp.begin(), vp.end(), cmp);
        for(auto i : vp) FOR(j, 1, i.se) cout << i.fi << ' ';
        cout << endl;
    }
    return 0;
}
