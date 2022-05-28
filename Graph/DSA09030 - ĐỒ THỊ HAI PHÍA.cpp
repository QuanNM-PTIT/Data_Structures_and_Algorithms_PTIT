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

vector<int> a[1005];
int clr[1005] = {};
bitset<1005> visited;
bool check;
int n, m;

inline void DFS(int u)
{
    visited[u] = 1;
    if(!check)
        return;
    for(int &i : a[u])
    {
        if(!visited[i])
        {
            if(!clr[i])
                clr[i] = 1 - clr[u];
            DFS(i);
        }
        else if(clr[u] == clr[i])
        {
            check = 0;
            return;
        }
    }
}

int main()
{
    faster();
    int t = 1, x, y;
    cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(m--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        check = 1;
        for(int i = 1; i <= n; ++i)
        {
            visited.reset();
            DFS(i);
            if(!check)
                goto End;
        }
        End:
        if(check)
            cout << "YES\n";
        else
            cout << "NO\n";
        for(int i = 1; i <= n; ++i)
        {
            a[i].clear();
            clr[i] = 0;
        }
    }
    return 0;
}