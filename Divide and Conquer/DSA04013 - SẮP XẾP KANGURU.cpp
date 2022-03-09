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
    int t = 1, n, cnt;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        sort(a, a + n);
        cnt = n;
        int l = n >> 1, r = n - 1, mid = n >> 1;
        --l;
        while(~l and r >= mid)
        {
            if(a[r] >= a[l] << 1)
            {
                --cnt;
                --l;
                --r;
            }
            else --l;
        }
        cout << cnt << endl;
    }
    return 0;
}