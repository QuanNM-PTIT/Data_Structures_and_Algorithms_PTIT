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
    int t = 1, n, m, x;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        m = n;
        set<int> s;
        vector<vector<int>> ans;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            s.insert(x);
            vector<int> v;
            for(int i : s) v.pb(i);
            ans.pb(v);
        }
        for(int i = ans.sz; i; --i)
        {
            cout << "Buoc " << i - 1 << ": ";
            for(int j : ans[i - 1]) cout << j << ' ';
            cout << endl;
        }
    }
    return 0;
}
