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
 
int main()
{
    faster();
    int t = 1, n, k, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi a(n);
        cin >> a[0];
        int m[n], M[n];
        M[0] = a[0];
        for(int i = 1; i < n; ++i)
        {
            cin >> a[i];
            M[i] = max(a[i], M[i - 1]);
        }
        m[n - 1] = a[n - 1];
        for(int i = n - 2; i >= 0; --i) m[i] = min(a[i], m[i + 1]);
        vi ans;
        --n;
        for(int i = 0; i < n; ++i) if(M[i] <= m[i + 1]) ans.pb(i + 1);
        if(ans.sz == 0) cout << 0 << endl << endl;
        else
        {
            cout << ans.sz << endl;
            for(int i : ans) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}

// 2 1 2 5 4 3