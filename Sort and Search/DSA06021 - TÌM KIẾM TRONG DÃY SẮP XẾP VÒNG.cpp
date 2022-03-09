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

int binSearchMin(int a[], int l, int r, int n)
{
    int mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(a[mid] > a[n - 1]) l = mid + 1;
        else r = mid - 1;
    }
    return mid;
}

int binSearch(int a[], int l, int r, int x)
{
    int mid;
    while(l <= r)
    {
        mid = l + (r - l) / 2;
        if(a[mid] == x) return mid;
        if(a[mid] < x) l = mid + 1;
        else r = mid - 1;
    }
    return mid;
}

int main()
{
    faster();
    int t = 1, n, m, x, posMin;
    cin >> t;
    while(t--)
    {
        cin >> n >> x;
        int a[n];
        for(int i = 0; i < n; ++i) cin >> a[i];
        posMin = binSearchMin(a, 0, n - 1, n);
        if(!posMin)
        {
            cout << binSearch(a, 0, n - 1, x) + 1 << endl;
            continue;
        }
        if(x < a[n - 1]) cout << binSearch(a, posMin, n - 1, x) + 1 << endl;
        else cout << binSearch(a, 0, posMin - 1, x) + 1 << endl;
    }
    return 0;
}