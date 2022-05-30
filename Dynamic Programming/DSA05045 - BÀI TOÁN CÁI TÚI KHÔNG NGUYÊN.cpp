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

inline bool cmp(pair<pair<int, int>, float> a, pair<pair<int, int>, float> b)
{
    return a.se > b.se;
}

int main()
{
    int t = 1;
    cin >> t;
    int n, w;
    while (t--)
    {
        cin >> n >> w;
        vector<pair<pair<int, int>, float>> v(n);
        for (pair<pair<int, int>, float> &i : v)
        {
            cin >> i.fi.fi >> i.fi.se;
            i.se = 1.0 * i.fi.fi / i.fi.se;
        }
        sort(all(v), cmp);
        int sumVal, idx;
        float sumWeight;
        idx = sumVal = sumWeight = 0;
        for (int i = 0; i < n; ++i)
        {
            if (sumVal <= w)
            {
                sumVal += v[i].fi.se;
                sumWeight += v[i].fi.fi;
                idx = i;
            }
        }
        if (sumVal > w)
            sumWeight -= 1.0 * (sumVal - w) * v[idx].se;
        cout << setprecision(2) << fixed << sumWeight << endl;
    }
    return 0;
}
