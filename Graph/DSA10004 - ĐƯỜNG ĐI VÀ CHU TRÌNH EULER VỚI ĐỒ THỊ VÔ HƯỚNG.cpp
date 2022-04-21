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
        int deg[1005] = {};
        cin >> v >> e;
        while(e--)
        {
            cin >> x >> y;
            ++deg[x];
            ++deg[y];
        }
        int cnt = 0;
        for(int i = 1; i <= v; ++i)
            cnt += deg[i] & 1;
        if(!cnt)
            cout << 2 << endl;
        else if(cnt == 2)
            cout << 1 << endl;
        else
            cout << 0 << endl;
    }
    return 0;
}
