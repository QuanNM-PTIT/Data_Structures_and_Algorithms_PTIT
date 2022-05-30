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
    int t = 1;
    cin >> t;
    int n;
    ll bitmask[10005][20] = {};
    const ll _oo = -1e18;
    while(t--)
    {
        cin >> n;
        ll a[4][n + 5];
        ll MAX = _oo;
        for(int i = 0; i < 4; ++i)
        {
            for(int j = 1; j <= n; ++j)
            {
                cin >> a[i][j];
                MAX = max(MAX, a[i][j]);
            }
        }
        bitset<20> f;
        if(MAX <= 0)
        {
            cout << MAX << endl;
            continue;
        }
        bool check;
        for(int i = 0; i < 16; ++i)
        {
            check = 1;
            for(int j = 0; j < 4; ++j)
            {
                if((i >> j) & 1 and (i >> (j + 1)) & 1)
                {
                    check = 0;
                    break;
                }
            }
            f[i] = check;
        }
        int sum;
        ll res = _oo;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = 0; j < 16; ++j)
            {
                bitmask[i][j] = _oo;
                if(f[j])
                {
                    sum = 0;
                    for(int z = 0; z < 4; ++z)
                        sum += a[z][i] * ((j >> z) & 1);
                    for(int z = 0; z < 16; ++z)
                        if(f[z] and !(j & z))
                            bitmask[i][j] = max(bitmask[i][j], bitmask[i - 1][z] + sum);
                }
                res = max(res, bitmask[i][j]);
            }
        }
        cout << res << endl;
    }
    return 0;
}
