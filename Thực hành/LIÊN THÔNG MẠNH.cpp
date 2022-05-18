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

vector<int> a[10005];
int cnt = 1, res = 0;
int dis[10005] = {}, low[10005] = {};
stack<int> st;

inline void DFS(int u)
{
    dis[u] = low[u] = cnt++;
    st.push(u);
    for(int &i : a[u])
    {
        if(dis[i])
            low[u] = min(low[u], dis[i]);
        else
        {
            DFS(i);
            low[u] = min(low[u], low[i]);
        }
    }
    if(dis[u] == low[u])
    {
        ++res;
        int i = st.top();
        st.pop();
        dis[i] = low[i] = 1e9;
        while(i != u)
        {
            i = st.top();
            st.pop();
            dis[i] = low[i] = 1e9;
        }
    }
}

int main()
{
    faster();
    int t = 1, n, m, x, y;
    //cin >> t;
    while(t--)
    {
        cin >> n >> m;
        while(m--)
        {
            cin >> x >> y;
            a[x].pb(y);
        }
        res = 0;
        for(int i = 1; i <= n; ++i)
            if(!dis[i])
                DFS(i);
        cout << res;
    }
    return 0;
}

