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
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        for(int &i : a) cin >> i;
        int MAX[n], ans = -1;
        MAX[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; --i) MAX[i] = max(MAX[i + 1], a[i]);
        int i, j;
        i = j = 0;
        while(i < n and j < n)
        {
            if(MAX[j] > a[i])
            {
                ans = max(ans, j - i);
                ++j;
            }
            else ++i;
        }
        if(!ans) ans = -1;
        cout << ans << endl;
    }
    return 0;
}