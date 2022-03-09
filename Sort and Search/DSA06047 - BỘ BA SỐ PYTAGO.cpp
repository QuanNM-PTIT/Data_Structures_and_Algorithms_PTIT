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

int Bsearch(const vll &v , int l, int r , ll x)
{
    while(l <= r)
    {
        int mid = (r + l) / 2;
        if (v[mid] == x) return mid;
        else if (v[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return -1;
}
 
bool check(const vll &v, int n)
{
    F(i, 0, n - 2)
    {
        F(j, i + 1, n - 1)
        {
            ll c = sqrt(v[i] * v[i] + v[j] * v[j]);
            if (c * c == v[i] * v[i] + v[j] * v[j])
            {
                int idx = Bsearch(v, j, n - 1, c);
                if (idx != -1) return 1;
            }
        }
    }
    return 0;
}
 
 
int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        vll v(n);
        F(i, 0, n) cin >> v[i];
        sort(v.begin(), v.end());
        if(check(v, n)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

