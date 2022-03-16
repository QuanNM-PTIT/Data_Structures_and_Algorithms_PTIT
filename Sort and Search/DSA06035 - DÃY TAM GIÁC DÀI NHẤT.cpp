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
    int n, a[100005];
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i) cin >> a[i];
        int inc[n], dec[n];
        inc[0] = dec[n - 1] = 1;
        for(int i = 1; i < n; ++i)
        {
            if(a[i] > a[i - 1]) inc[i] = inc[i - 1] + 1;
            else inc[i] = 1;
        }
        for(int i = n - 2; i >= 0; --i)
        {
            if(a[i] > a[i + 1]) dec[i] = dec[i + 1] + 1;
            else dec[i] = 1;
        }
        int ans = -1;
        for(int i = 0; i < n; ++i) ans = max(ans, inc[i] + dec[i] - 1);
        cout << ans << endl;
    }
    return 0;
}
