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

string calc(int *a, int n, unordered_map<int, int> &m)
{
    for(int i = 0; i < n; ++i) if(m[a[i]] > 1) return to_string(a[i]);
    return "NO";
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    int n, a[100005];
    while(t--)
    {
        cin >> n;
        unordered_map<int, int> m;
        for(int i = 0; i < n; ++i)
        {
            cin >> a[i];
            ++m[a[i]];
        }
        cout << calc(a, n, m) << endl;
    }
    return 0;
}
