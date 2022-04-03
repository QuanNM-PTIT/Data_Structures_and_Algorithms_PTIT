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

int n, s, MIN = 35;
int a[35];
vector<int> v;

void Try(int i, ll sum = 0)
{
    if(sum == s)
    {
        MIN = min(MIN, (int) v.sz);
        return;
    }
    for(int j = i; j < n; ++j)
    {
        if(sum + a[j] <= s and v.sz < MIN)
        {
            v.pb(a[j]);
            Try(j + 1, sum + a[j]);
            v.pop_back();
        }
    }
}

int main()
{
    faster();
    cin >> n >> s;
    for(int i = 0; i < n; ++i)
        cin >> a[i];
    Try(0);
    if(MIN < 35)
    	cout << MIN;
    else
        cout << -1;
    return 0;
}