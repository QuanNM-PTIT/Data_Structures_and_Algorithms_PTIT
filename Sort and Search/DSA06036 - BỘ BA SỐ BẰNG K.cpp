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

bool check(int a[], int n, int k)
{
    for(int i = 0; i < n; ++i)
    {
        for(int j = i + 1; j < n; ++j)
        {
            if(a[i] + a[j] > k) break;
            else if(binary_search(a + j + 1, a + n, k - a[i] - a[j])) return 1;
        }
    }
    return 0;
}

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[n];
        for(int &i : a) cin >> i;
        sort(a, a + n);
        if(check(a, n, k)) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}
