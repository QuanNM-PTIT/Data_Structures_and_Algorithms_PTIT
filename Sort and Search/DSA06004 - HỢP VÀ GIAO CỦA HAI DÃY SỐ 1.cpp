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
    int t = 1, n, m;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        vector<int> v1(n), v2(m);
        vector<int> ans;
        int a[100005] = {}, b[100005] = {};
        for(int &i : v1)
        {
            cin >> i;
            ++a[i];
        }
        for(int &i : v2)
        {
            cin >> i;
            ++b[i];
        }
        set<int> s;
        for(int i : v1)
        {
            if(b[i])
            {
                ans.pb(i);
                b[i] = 0;
            }
            s.insert(i);
        }
        for(int i : v2) s.insert(i);
        for(int i : s) cout << i << ' ';
        cout << endl;
        for(int i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
