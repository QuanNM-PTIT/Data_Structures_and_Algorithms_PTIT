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
    stack<int> stL, stR;
    for(int &i : a)
        cin >> i;
    int L[n], R[n];
    for(int i = 0; i < n; ++i)
    {
        while(stL.sz and a[i] <= a[stL.top() - 1])
            stL.pop();
        if(stL.empty())
            L[i] = 0;
        else
            L[i] = stL.top();
        stL.push(i + 1);
    }
    for(int i = n - 1; ~i; --i)
    {
        while(stR.sz and a[i] <= a[stR.top() + 1])
            stR.pop();
        if(stR.empty())
            R[i] = n - 1;
        else
            R[i] = stR.top();
        stR.push(i - 1);
    }
    ll res = -1;
    for(int i = 0; i < n; ++i)
        res = max(res, 1LL * a[i] * (R[i] - L[i] + 1));
    cout << res;
    return 0;
}
