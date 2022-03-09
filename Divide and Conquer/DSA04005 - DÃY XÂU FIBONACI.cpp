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
    ll f[93];
    f[1] = f[2] = 1;
    for(int i = 3; i <= 92; ++i) f[i] = f[i - 1] + f[i - 2];
    int t = 1;
    ll n, k;
    string s = "AAB";
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        while(n > 2)
        {
            if(k <= f[n - 2]) n -= 2;
            else
            {
                k -= f[n - 2];
                --n;
            }
        }
        cout << s[n] << endl;
    }
    return 0;
}
