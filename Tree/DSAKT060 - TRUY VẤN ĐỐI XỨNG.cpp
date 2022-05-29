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

int n, q;
string s;
const int N = 1e5 + 5, Prime = 17;
ll Pow[N], Fenwick1[N], Fenwick2[N];

inline void Update(int idx, int x)
{
    ll val = Pow[idx] * x;
    for(int i = idx; i <= n; i += (i & -i))
        Fenwick1[i] += val;
    val = Pow[n - idx + 1] * x;
    while(idx)
    {
        Fenwick2[idx] += val;
        idx -= (idx & -idx);
    }
}

inline ll Get1(int idx)
{
    ll res = 0;
    while(idx)
    {
        res += Fenwick1[idx];
        idx -= (idx & -idx);
    }
    return res;
}

inline ll Get2(int idx)
{
    ll res = 0;
    while(idx <= n)
    {
        res += Fenwick2[idx];
        idx += (idx & -idx);
    }
    return res;
}
int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> s >> q;
        n = s.sz;
        s = "*" + s;
        Pow[0] = 1;
        for(int i = 1; i <= n; ++i)
            Pow[i] = Pow[i - 1] * Prime;
        for(int i = 1; i <= n; ++i)
            Update(i, s[i]);
        int l, r;
        char c, x;
        while(q--)
        {
            cin >> c;
            if(c == 'c')
            {
                cin >> l >> x;
                Update(l, x - s[l]);
                s[l] = x;
            }
            else
            {
                cin >> l >> r;
                if(((Get1(r) - Get1(l - 1)) * Pow[n - r + 1] == (Get2(l) - Get2(r + 1)) * Pow[l]))
                    cout << "YES\n";
                else
                    cout << "NO\n";
            }
        }
    }
    return 0;
}