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
    int t = 1, n, MAX;
    cin >> t;
    while(t--)
    {
        cin >> n;
        MAX = 1 << n;
        vector<ll> ans;
        for(int i = 0; i < MAX; ++i)
        {
            string s = "";
            for(int j = n - 1; ~j; --j)
                if((i >> j) & 1)
                    s += '8';
                else
                    s += '6';
            ans.pb(stoll(s));
        }
        cout << ans.sz << endl;
        for(ll &i : ans)
            cout << i << ' ';
        cout << endl;
    }
    return 0;
}
