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

inline bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.se < b.se;
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<pair<int, int>> vp(n);
        F(i, 0, n) cin >> vp[i].fi >> vp[i].se;
        sort(all(vp), cmp);
        int cnt = 0;
        int last = 0;
        for(pair<int, int> i : vp)
        {
            if(i.first < last) continue;
            last = i.second;
            ++cnt;
        }
        cout << cnt << endl;
    }
    return 0;
}
