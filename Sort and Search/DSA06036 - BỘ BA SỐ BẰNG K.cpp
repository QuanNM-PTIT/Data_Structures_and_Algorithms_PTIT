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

inline string calc(vi &a, int &k)
{
    int n = a.sz, l, r;
    for(int i = 0; i < n; ++i)
    {
        l = i + 1;
        r = n - 1;
        while(l < r)
        {
            if(a[i] + a[l] + a[r] == k) return "YES";
            if(a[i] + a[l] + a[r] < k) ++l;
            else --r;
        }
    }
    return "NO";
}

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        vi a(n);
        for(int &i : a) cin >> i;
        sort(all(a));
        cout << calc(a, k) << endl;
    }
    return 0;
}