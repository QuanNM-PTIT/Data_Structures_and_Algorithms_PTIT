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
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ll res = 0;
        int a[n];
        for(int &i : a)
            cin >> i;
        int MAX, MIN;
        for(int i = 0; i < n - 1; ++i)
        {
            MAX = max(a[i], a[i + 1]);
            MIN = min(a[i], a[i + 1]);
            while(MAX > (MIN << 1))
            {
                ++res;
                MIN <<= 1;
            }
        }
        cout << res << endl;
    }
    return 0;
}
