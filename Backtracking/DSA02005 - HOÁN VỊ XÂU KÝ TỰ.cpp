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

int calc(int n)
{
    int res = 1;
    for(int i = 2; i <= n; ++i) res *= i;
    return res;
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        string s;
        cin >> s;
        int cnt = calc((int) s.sz);
        while(cnt--)
        {
            cout << s << ' ';
            next_permutation(all(s));
        }
        cout << endl;
    }
    return 0;
}
