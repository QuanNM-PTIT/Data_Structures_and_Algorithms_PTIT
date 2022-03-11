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

// {Fn, Tn, Tn-1, Tn-2}

ll mod = 1e15 + 7;
int n;

inline ll binMul(ll a, ll b)
{
    if(b == 0) return 0;
    ll res = binMul(a, b >> 1) % mod;
    res = (res + res) % mod;
    if(b & 1) res = (res + a) % mod;
    return res;
}

struct matrix
{
    ll m[5][5];
    
    matrix operator * (matrix a)
    {
        matrix res, b = *this;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 0; j < 4; ++j)
            {
                res.m[i][j] = 0;
                for(int z = 0; z < 4; ++z)
                {
                    res.m[i][j] += binMul(a.m[i][z], b.m[z][j]) % mod;
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

ll x[] = {6, 3, 2, 1};

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(!n) cout << 0 << endl;
        else if(n == 1) cout << 1 << endl;
        else if(n == 2) cout << 3 << endl;
        else if(n == 3) cout << 6 << endl;
        else
        {
            matrix a, res;
            for(int i = 0; i < 4; ++i)
                for(int j = 0; j < 4; ++j)
                    a.m[i][j] = 0;
            a.m[0][0] = a.m[0][1] = a.m[0][2] = a.m[0][3] = a.m[1][1] = a.m[1][2] = a.m[1][3] = a.m[2][1] = a.m[3][2] = 1;
            res = binPow(a, n - 3);
            ll ans = 0;
            for(int i = 0; i < 4; ++i) ans = (ans + binMul(res.m[0][i], x[i])) % mod;
            cout << ans << endl;
        }
    }
    return 0;
}