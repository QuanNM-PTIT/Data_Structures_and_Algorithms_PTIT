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

int main()
{
    faster();
    int t = 1;
    cin >> t;
    ll n, k, a[5005], tmp, idx;
    while(t--)
    {
        ll cnt = 0;
        cin >> n >> k;
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        for(int i = 0; i < n; ++i)
        {
            if(a[i] > k) break;
            for(int j = i + 1; j < n; ++j)
            {
                idx = upper_bound(a + j + 1, a + n, k - a[i] - a[j] - 1) - a;
                if(idx > j) cnt += idx - j - 1;
                else break;
            }
        }
        cout << cnt << endl;
    }
    return 0;
}