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

int n, mod = 1e9 + 7;

struct matrix
{
    long long a[15][15];
    
    matrix operator * (matrix A)
    {
        matrix res, B = *this;
        for(int i = 0; i < n; ++i)
        {
            for(int j = 0; j < n; ++j)
            {
                res.a[i][j] = 0;
                for(int z = 0; z < n; ++z)
                {
                    res.a[i][j] += A.a[i][z] * B.a[z][j] % mod;
                    res.a[i][j] %= mod;
                }
            }
        }
        return res;
    }
};

matrix binPow(matrix A, long long k)
{
    if(k == 1)
        return A;
    matrix res = binPow(A, k / 2);
    res = res * res;
    if(k % 2 == 1)
        res = res * A;
    return res;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        long long k;
        cin >> n >> k;
        matrix A, res;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < n; ++j)
                cin >> A.a[i][j];
        res = binPow(A, k);
        long long sum = 0;
        for(int i = 0; i < n; ++i)
            sum = (sum + res.a[0][i]) % mod;
        cout << sum % mod << endl;
    }
}