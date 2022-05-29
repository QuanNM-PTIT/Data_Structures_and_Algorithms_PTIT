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

vector<int> a[10005], b[10005];
bitset<10005> visited;
int cnt, res;
int dis[10005] = {}, low[10005] = {};
int n, m;
stack<int> st;

inline void DFS(vector<int> c[], int u)
{
    visited[u] = 1;
    for(int &i : c[u])
        if(!visited[i])
            DFS(c, i);
}

inline void DFS2(int u)
{
    dis[u] = low[u] = cnt++;
    st.push(u);
    for(int &i : a[u])
    {
        if(dis[i])
            low[u] = min(low[u], dis[i]);
        else
        {
            DFS2(i);
            low[u] = min(low[u], low[i]);
        }
    }
    if(dis[u] == low[u])
    {
        ++res;
        int top = st.top();
        st.pop();
        dis[top] = low[top] = 1e9;
        while(top != u)
        {
            top = st.top();
            st.pop();
            dis[top] = low[top] = 1e9;
        }
    }
}

inline bool check()
{
    for(int i = 1; i <= n; ++i)
        if(!visited[i])
            return 0;
    return 1;
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
            b[y].pb(x);
        }
        DFS(a, 1);
        if(check())
        {
            visited.reset();
            DFS(b, 1);
            if(check())
                cout << "YES\n";
            else
                goto A;
        }
        else
        {
            A:
            cnt = 1;
            res = 0;
            for(int i = 1; i <= n; ++i)
                if(!dis[i])
                    DFS2(i);
            cout << "NO " << res << endl;
            memset(dis, 0, sizeof(low));
            memset(low, 0, sizeof(dis));
        }
        visited.reset();
        for(int i = 1; i <= n; ++i)
        {
            a[i].clear();
            b[i].clear();
        }
        st = {};
    }
    return 0;
}
