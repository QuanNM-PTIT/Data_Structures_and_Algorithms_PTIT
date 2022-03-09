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
    int t = 1, n;
    ll k;
    ll a[93];
    a[1] = a[2] = 1;
    for(int i = 3; i < 93; ++i) a[i] = a[i - 1] + a[i - 2];
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        while(n > 2)
        {
            if(k > a[n - 2])
            {
                k -= a[n - 2];
                --n;
            }
            else n -= 2;
        }
        cout << n - 1 << endl;
    }
    return 0;
}