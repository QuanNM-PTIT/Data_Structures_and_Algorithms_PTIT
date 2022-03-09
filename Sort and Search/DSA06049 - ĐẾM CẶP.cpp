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
    int n, a[100005], k;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0; i < n; ++i) cin >> a[i];
        sort(a, a + n);
        ll cnt = 0;
        for(int i = 0; i < n; ++i) cnt += lower_bound(a + i + 1, a + n, k + a[i]) - a - i - 1;
        cout << cnt << endl;
    }
    return 0;
}