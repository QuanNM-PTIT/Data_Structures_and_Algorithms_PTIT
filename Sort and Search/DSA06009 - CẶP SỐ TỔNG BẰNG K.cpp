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
    int t = 1, n, k, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int f[105] = {};
        int cnt = 0;
        while(n--)
        {
            cin >> x;
            ++f[x];
        }
        if((k & 1) ^ 1 and f[k >> 1])
        {
            cnt += f[k >> 1] * (f[k >> 1] - 1) >> 1;
            f[k >> 1] = 0;
        }
        for(int i = 0; i <= k; ++i)
        {
            if(f[i])
            {
                cnt += f[i] * f[k - i];
                f[i] = f[k - i] = 0;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}