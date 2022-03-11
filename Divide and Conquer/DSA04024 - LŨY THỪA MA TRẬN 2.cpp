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

ll mod = 1e9 + 7;
int n, k;

struct matrix
{
    ll m[15][15];
    
    matrix operator * (matrix a)
    {
        matrix res, b = *this;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res.m[i][j] = 0;
                for(int z = 0; z < n; ++z)
                {
                    res.m[i][j] += (a.m[i][z] * b.m[z][j]) % mod;
                    res.m[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

inline matrix binPow(matrix a, int b)
{
    if(b == 1) return a;
    matrix res = binPow(a, b >> 1);
    res = res * res;
    if(b & 1) res = res * a;
    return res;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        matrix a, res;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> a.m[i][j];
        res = binPow(a, k);
        ll ans = 0;
        for(int i = 0; i < n; ++i) ans = (ans + res.m[i][n - 1]) % mod;
        cout << ans << endl;
    }
    return 0;
}
