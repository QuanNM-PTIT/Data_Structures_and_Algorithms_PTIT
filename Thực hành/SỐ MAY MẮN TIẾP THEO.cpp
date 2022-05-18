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
    //cin >> t;
    while(t--)
    {
        queue<ll> q;
        vll luckyNum;
        q.push(4);
        q.push(7);
        luckyNum.pb(4);
        luckyNum.pb(7);
        ll top, x, y;
        while(q.front() <= 1e9)
        {
            top = q.front();
            q.pop();
            x = top * 10 + 4;
            y = top * 10 + 7;
            q.push(x);
            q.push(y);
            luckyNum.pb(x);
            luckyNum.pb(y);
        }
        int a, b, idx;
        cin >> a >> b;
        ll res = 0, cnt = 0;
        idx = lower_bound(all(luckyNum), a) - luckyNum.begin();
        while(a <= b)
        {
            cnt = min(luckyNum[idx], 1LL * b) - a + 1;
            res += cnt * luckyNum[idx];
            a = luckyNum[idx] + 1;
            ++idx;
        }
        cout << res;
    }
    return 0;
}
