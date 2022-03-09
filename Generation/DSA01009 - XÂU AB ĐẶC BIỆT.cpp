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
vector<bool> a;
vector<vector<bool>> ans;

void check()
{
    int cnt = 0, res = 0;
    for(int i = 1; i <= n; ++i)
    {
        if(a[i])
        {
            res += cnt == k;
            cnt = 0;
        }
        else ++cnt;
    }
    res += cnt == k;
    if(res == 1) ans.pb(a);
}

void sinh()
{
    while(1)
    {
        for(int i = n; i >= 0; --i)
        {
            if (i == 0) return;
            if (a[i] == 1) a[i] = 0;
            else
            {
                a[i] = 1;
                check();
                break;
            }
        }
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
        a.resize(n + 1, 0);
        sinh();
        cout << ans.size() << endl;
        for(vector<bool> &i : ans)
        {
            for(int j = 1; j < i.sz; ++j)
            {
                if(!i[j]) cout << 'A';
                else cout << 'B';
            }
            cout << endl;
        }
    }
    return 0;
}
