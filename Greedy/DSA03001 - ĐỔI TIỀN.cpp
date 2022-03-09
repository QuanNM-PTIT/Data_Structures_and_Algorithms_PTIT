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
    int t = 1, n, idx;
    int a[] = {1, 2, 5, 10, 20, 50, 100, 200, 500, 1000};
    cin >> t;
    ll x;
    while(t--)
    {
        cin >> n;
        int cnt = 0, i = 9;
        while(n)
        {
            cnt += n / a[i];
            n %= a[i];
            --i;
        }
        cout << cnt << endl;
    }
    return 0;
}
