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

double res;
vector<pair<double, double>> vp(100000), tmp(100000);

inline double dist(pair<double, double> &a, pair<double, double> &b)
{
    return sqrt((a.fi - b.fi) * (a.fi - b.fi) + (a.se - b.se) * (a.se - b.se));
}

inline bool cmp(pair<double, double> a, pair<double, double> b)
{
    return a.se < b.se;
}

inline void solve(int l, int r)
{
    if(r <= l) return;
    if(r == l + 1)
    {
        res = min(res, dist(vp[l], vp[r]));
        if(vp[l] >= vp[r]) swap(vp[l], vp[r]);
        return;
    }
    int mid = (l + r) >> 1;
    int midVal = vp[mid].fi;
    solve(l, mid);
    solve(mid + 1, r);
    merge(vp.begin() + l, vp.begin() + mid + 1, vp.begin() + mid + 1, vp.begin() + r + 1, tmp.begin(), cmp);
    copy(tmp.begin(), tmp.begin() + r - l + 1, vp.begin() + l);
    int idx = 0;
    for(int i = l; i <= r; ++i)
    {
        if(res > abs(midVal - vp[i].fi))
        {
            for(int j = idx - 1; tmp[j].se > vp[i].se - res and j >= 0; --j) res = min(res, dist(vp[i], tmp[j]));
            tmp[idx++] = vp[i];
        }
    }
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> vp[i].fi >> vp[i].se;
        sort(vp.begin(), vp.begin() + n);
        res = DBL_MAX;
        solve(0, n - 1);
        cout << setprecision(6) << fixed << res << endl;
    }
    return 0;
}
