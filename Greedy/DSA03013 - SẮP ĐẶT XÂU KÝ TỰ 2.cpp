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
    int t = 1;
    cin >> t;
    while(t--)
    {
        int n, res = 0;
        cin >> n;
        int dd[30] = {};
        string s;
        cin >> s;
        for(char &i : s) ++dd[i - 'A'];
        for(int i = 0; i < 26; i++) res = max(res, dd[i]);
        int k = s.sz - (n - 1) * (res - 1);
        if(res <= k) cout << 1;
        else cout << -1;
        cout << endl;
    }
    return 0;
}
