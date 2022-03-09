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

inline bool check(int n, vi &v)
{
    for(int &i : v) if(i / n == i / (n + 1)) return 0;
    return 1;
}

int main()
{
    faster();
    int t = 1, n;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        vi a(n), b(n), c(n);
        for(int &i : a) cin >> i;
        b = c = a;
        sort(all(b));
        for(int i = b[0]; i; --i)
        {
            if(check(i, a))
            {
                for(int j = 0; j < n; ++j) c[j] = a[j] / (i + 1) + 1;
                break;
            }
        }
        int res = 0;
        for(int &i : c) res += i;
        cout << res << endl;
    }
    return 0;
}
