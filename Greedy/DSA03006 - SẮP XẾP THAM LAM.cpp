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

inline string calc(vi &a, vi &b)
{
    for(int i = 0; i < a.sz; ++i) if(a[i] != b[i] and a[i] != b[a.sz - i - 1]) return "No";
        return "Yes";
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi a(n), b(n);
        for(int &i : a) cin >> i;
        b = a;
        sort(all(b));
        cout << calc(a, b) << endl;
    }
    return 0;
}
