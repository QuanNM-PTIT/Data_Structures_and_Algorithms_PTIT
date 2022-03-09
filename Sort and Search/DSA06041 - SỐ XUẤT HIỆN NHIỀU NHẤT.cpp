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
        int a[n], idx = 0;
        int f[1000005] = {};
        for(int i = 0; i < n; ++i)
        {
            cin >> k;
            if(!f[k]) a[idx++] = k;
            ++f[k];
        }
        n >>= 1;
        int ans = -1, num;
        for(int i = 0; i < idx; ++i)
        {
            if(f[a[i]] > n and f[a[i]] > ans)
            {
                ans = f[a[i]];
                num = a[i];
            }
        }
        if(ans == -1) cout << "NO\n";
        else cout << num << endl;
    }
    return 0;
}