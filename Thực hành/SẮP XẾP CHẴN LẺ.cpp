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
    int n, x;
    cin >> n;
    bitset<1005> bs;
    vector<int> odd, even;
    for(int i = 0; i < n; ++i)
    {
        cin >> x;
        bs[i] = x & 1;
        if(bs[i])
            odd.pb(x);
        else
            even.pb(x);
    }
    sort(all(odd));
    sort(all(even), greater<int>());
    for(int i = 0; i < n; ++i)
    {
        if(bs[i])
        {
            cout << odd.back() << ' ';
            odd.pop_back();
        }
        else
        {
            cout << even.back() << ' ';
            even.pop_back();
        }
    }
    return 0;
}
