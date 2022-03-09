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

int n, k, sum, res;
bool dd[25];
vector<int> a;

void Try(int i, int cur = 0)
{
    if(i > k)
    {
        res += cur == sum;
        return;
    }
    for(int j = a[i - 1] + 1; j <= n; ++j)
        if (!dd[j])
        {
            a.pb(j);
            dd[j] = 1;
            Try(i + 1, cur + j);
            a.pop_back();
            dd[j] = 0;
        }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        while(1)
        {
            res = 0;
            cin >> n >> k >> sum;
            if(n == 0 && k == 0 && sum == 0) return 0;
            a.pb(0);
            Try(1);
            cout << res << endl;
            a.clear();
        }
    }
    return 0;
}
