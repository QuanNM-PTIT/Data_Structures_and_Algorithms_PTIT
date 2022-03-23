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

int n;
vi a;
vector<vi> ans;

void Try(int i, vi v, int sum = 0)
{
    if(sum > n)
        return ;
    if(sum == n)
    {
        ans.pb(v);
        return;
    }
    for(int j = i; j < a.sz; ++j)
    {
        v.pb(a[j]);
        Try(j, v, sum + a[j]);
        v.pop_back();
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        vi v;
        cin >> n;
        a.resize(n);
        for(int i = n; i > 0; --i)
            a[n - i] = i;
        Try(0, v);
        cout << ans.sz << endl;
        for(vector<int> &i : ans)
        {
            cout << '(';
            for(int j = 0; j < i.sz - 1; ++j)
                cout << i[j] << ' ' ;
            cout << i.back() << ')' << ' ';
        }
        cout << endl;
        ans.clear();
    }
    return 0;
}
