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
 
int a[1005];

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        FOR(i, 1, k) cin >> a[i];
        int tmp = k;
        while(a[tmp - 1] + 1 == a[tmp] && tmp) --tmp;
        if(tmp)
        {
            --a[tmp];
            FOR(i, tmp + 1, k) a[i] = n - k + i;
            FOR(i, 1, k) cout << a[i] << ' ';
        }
        else FOR(i, n - k + 1, n) cout << i << ' ';
        cout << endl;
    }
    return 0;
}