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

int n, k;
vector<vi> a(10, vi (10));
vector<vi> ans;
vi tmp;

void Try(int i)
{
    if(i == n)
    {
        int sum = 0;
        bitset<10> f;
        int idx = 0;
        for(int &j : tmp)
        {
            if(f[j]) return;
            sum += a[idx++][j];
            f[j] = 1;
        }
        if(sum == k) ans.pb(tmp);
        return;
    }
    for(int j = 0; j < n; ++j)
    {
        tmp.pb(j);
        Try(i + 1);
        tmp.pop_back();
    }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                cin >> a[i][j];
        Try(0);
        cout << ans.sz <<endl;
        for(vector<int> &i : ans)
        {
            for(int &j : i) cout << j + 1 << ' ';
            cout << endl;
        }
    }
    return 0;
}
