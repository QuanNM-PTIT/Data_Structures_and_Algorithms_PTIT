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

vector<vector<int>> a;
bitset<1005> bs;
bool check;
int trace[1005];
int en;

void DFS(int u, int par)
{
    if(check)
        return;
    bs[u] = 1;
    for(int &i : a[u])
    {
        if(!bs[i])
        {
            trace[i] = u;
            DFS(i, u);
        }
        else
        {
            if(i != trace[u] and i == 1)
            {
                check = 1;
                en = u;
                return;
            }
        }
    }
}

int main()
{
    faster();
    int t, v, e, x, y;
    cin >> t;
    while(t--)
    {
        memset(trace, 0, sizeof(trace));
        cin >> v >> e;
        a.resize(v + 5);
        while(e--)
        {
            cin >> x >> y;
            a[x].pb(y);
            a[y].pb(x);
        }
        for(int i = 1; i <= v; ++i)
            sort(all(a[i]));
        check = 0;
        DFS(1, 0);
        if(check)
        {
            stack<int> st;
            cout << 1 << ' ';
            while(trace[en])
            {
                st.push(en);
                en = trace[en];
            }
            while(st.sz)
            {
                cout << st.top() << ' ';
                st.pop();
            }
            cout << 1;
        }
        else
            cout << "NO";
        bs.reset();
        a.clear();
        cout << endl;
    }
    return 0;
}
