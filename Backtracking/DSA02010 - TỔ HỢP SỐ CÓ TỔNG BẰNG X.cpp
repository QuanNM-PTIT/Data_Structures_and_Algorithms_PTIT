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

bool check;
vector<int> res;
int n, sum;

void Try(vector<int> &a, int i = 0, int cur = 0)
{
    if(cur > sum) return;
    if(cur == sum)
    {
        check = 1;
        cout << "[";
        int s = res.sz - 1;
        for(int j = 0; j < s; ++j) cout << res[j] << ' ';
        cout << res.back() << "]";
        return;
    }
    for(int j = i; j < a.sz; ++j)
    {
        res.pb(a[j]);
        Try(a, j, cur + a[j]);
        res.pop_back();
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        check = 0;
        cin >> n >> sum;
        vector<int> a(n);
        for(int i = 0; i < n; i++) cin >> a[i];
        sort(a.begin(), a.end());
        Try(a);
        if(!check) cout << -1;
        cout << endl;
        res.clear();
    }
    return 0;
}