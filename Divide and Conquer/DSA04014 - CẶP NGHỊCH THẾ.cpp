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

inline ll Merge(ll *a, ll l, ll r, ll mid)
{
    ll i, j, k;
    ll p1 = mid - l + 1, p2 = r - mid;
    ll L[p1], R[p2];
    for(i = 0; i < p1; ++i) L[i] = a[l + i];
    for(i = 0; i < p2; ++i) R[i] = a[mid + i + 1];
    ll res = 0;
    i = j = 0;
    k = l;
    while(i < p1 and j < p2)
    {
        if(L[i] <= R[j]) a[k++] = L[i++];
        else
        {
            a[k++] = R[j++];
            res += p1 - i;
        }
    }
    while(i < p1) a[k++] = L[i++];
    while(j < p2) a[k++] = R[j++];
    return res;
}

inline ll calc(ll *a, int l, int r)
{
    ll res = 0;
    int mid;
    if(l < r)
    {
        mid = (l + r) >> 1;
        res += calc(a, l, mid);
        res += calc(a, mid + 1, r);
        res += Merge(a, l, r, mid);
    }
    return res;
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll a[n];
        for(ll &i : a) cin >> i;
        cout << calc(a, 0, n - 1) << endl;
    }
    return 0;
}