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
    int t = 1, n;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        vi v(n);
        for(int &i : v) cin >> i;
        int m = n - 1;
        for(int i = 0; i < m; ++i)
        {
            cout << "Buoc " << i + 1 << ": ";
            for(int j = i + 1; j < n; ++j) if(v[i] > v[j]) swap(v[i], v[j]);
            for(int i : v) cout << i << ' ';
            cout << endl;
        }
    }
    return 0;
}
