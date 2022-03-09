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
    int t = 1, x, y, z, a;
    cin >> t;
    while(t--)
    {
        cin >> x >> y >> z;
        ll a[x], b[y], c[z];
        F(i, 0, x) cin >> a[i];
        F(i, 0, y) cin >> b[i];
        F(i, 0, z) cin >> c[i];
        int idxA, idxB, idxC;
        idxA = idxB = idxC = 0;
        multiset<ll> ans;
        while(idxA < x && idxB < y && idxC < z)
        {
            if(a[idxA] == b[idxB] && b[idxB] == c[idxC])
            {
                ans.insert(a[idxA]);
                ++idxA;
                ++idxB;
                ++idxC;
            }
            else if(a[idxA] < b[idxB]) ++idxA;
            else if(b[idxB] < c[idxC]) ++idxB;
            else ++idxC;
        }
        if(ans.empty()) cout << -1;
        else for(ll i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
