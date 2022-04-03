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
    int n;
    cin >> n;
    int a[n];
    for(int &i : a)
        cin >> i;
    int MAX = -1;
    for(int i = 1; i < n; ++i)
        MAX = max(MAX, a[i]);
    int res = 0, cur = 0;
    for(int i = 0; i < n; ++i)
    {
        if(a[i] == MAX)
            ++cur;
        else
        {
            res = max(res, cur);
            cur = 0;
        }
    }
    cout << max(res, cur);
    return 0;
}
