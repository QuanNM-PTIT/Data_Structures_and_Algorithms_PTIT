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

bool notPrime[1000010] = {};

int calc(int &n)
{
    int mid = n >> 1;
    for(int i = 2; i <= mid; ++i) if(!notPrime[i] and !notPrime[n - i]) return i;
    return -1;
}

int main()
{
    faster();
    int t = 1, n, k;
    int N = 1e6 + 5;
    int sqr = sqrt(N);
    notPrime[0] = notPrime[1] = 1;
    for(int i = 2; i <= sqr; ++i)
        if(!notPrime[i])
            for(int j = i * i; j <= 1e6; j += i)
                notPrime[j] = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int ans = calc(n);
        if(ans == -1) cout << ans << endl;
        else cout << ans << ' ' << n - ans << endl;
    }
    return 0;
}
