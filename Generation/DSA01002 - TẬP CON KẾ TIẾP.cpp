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
    string s;
    while(t--)
    {
        int a[1005];
        cin >> n >> k;
        FOR(i, 1, k) cin >> a[i];
        int tmp = k;
        while(a[tmp] == n - k + tmp) --tmp;
        if(tmp > 0)
        {
            ++a[tmp];
            FOR(i, tmp + 1, k) a[i] = a[i - 1] + 1;
            FOR(i, 1, k) cout << a[i] << ' ';
        }
        else FOR(i, 1, k) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
