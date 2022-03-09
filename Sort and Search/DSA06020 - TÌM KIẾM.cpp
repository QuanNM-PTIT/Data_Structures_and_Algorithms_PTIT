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

int bS(int a[], int &n, int &x)
{
    if(binary_search(a, a + n, x) == 1) return 1;
    return -1;
}

int main()
{
    faster();
    int t = 1, n, m, x;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        cout << bS(a, n, x) << endl;
    }
    return 0;
}