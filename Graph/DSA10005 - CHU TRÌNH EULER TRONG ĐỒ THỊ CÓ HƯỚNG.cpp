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

int main()
{
    faster();
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        int degc[1005] = {}, degt[1005] = {};
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            ++degc[x];
            ++degt[y];
        }
        int cnt = 0;
        bool check = 1;
        for(int i = 1; i <= v; ++i)
        {
            cnt += (abs(degc[i] - degt[i]) == 1);
            if(cnt > 2 or abs(degc[i] - degt[i]) > 1 or !degc[i] or !degt[i])
            {
                check = 0;
                break;
            }
        }
        if(check)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}