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

vector<map<int, int>> dp;

inline bool check(int mid, int x, int y)
{
    auto it = dp[mid].lower_bound(x);
    if(it == dp[mid].begin())
        return 0;
    --it;
    return (*it).se < y;
}

inline void Add(int l, int x, int y)
{
    auto it = dp[l].lower_bound(x);
    auto ori = it;
    while(it != dp[l].end() and (*it).se >= y)
        ++it;
    dp[l].erase(ori, it);
    dp[l].insert({x, y});
}

int main()
{
    faster();
    int n, x, y, res = 0, l, r, mid;
    cin >> n;
    dp.resize(n);
    Add(0, INT_MIN, INT_MIN);
    while(n--)
    {
        cin >> x >> y;
        l = 0;
        r = res;
        while(l <= r)
        {
            mid = (l + r) >> 1;
            if (check(mid, x, y))
                l = mid + 1;
            else
                r = mid - 1;
        }
        if(res == l - 1)
            res = l;
        Add(l, x, y);
    }
    cout << res;
    return 0;
}