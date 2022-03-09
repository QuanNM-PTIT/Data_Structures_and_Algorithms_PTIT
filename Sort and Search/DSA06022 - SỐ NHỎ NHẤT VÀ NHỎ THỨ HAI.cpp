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

int main()
{
    faster();
    int t = 1, n, m, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        sort(a, a + n);
        if(a[0] == a[n - 1]) cout << -1 << endl;
        else
        {
            int idx = 1;
            while(a[idx] == a[0]) ++idx;
            cout << a[0] << ' ' << a[idx] << endl;
        }
    }
    return 0;
}