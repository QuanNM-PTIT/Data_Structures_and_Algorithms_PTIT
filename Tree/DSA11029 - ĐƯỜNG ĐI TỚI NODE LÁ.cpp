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

void BFS(vector<int> a[], int trace[])
{
    queue<int> q;
    bitset<1005> visited;
    visited[1] = 1;
    q.push(1);
    int top;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int &i : a[top])
        {
            if(!visited[i])
            {
                visited[i] = 1;
                trace[i] = top;
                q.push(i);
            }
        }
    }
}

void findPath(int trace[], int E)
{
    stack<int> path;
    path.push(E);
    while(trace[E])
    {
        E = trace[E];
        path.push(E);
    }
    while(path.sz)
    {
        cout << path.top() << ' ';
        path.pop();
    }
    cout << endl;
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> a[n + 5];
        int x, y;
        bitset<1005> f;
        for(int i = 1; i < n; ++i)
        {
            cin >> x >> y;
            a[x].pb(y);
            f[x] = 1;
        }
        int trace[1005] = {};
        BFS(a, trace);
        for(int i = 2; i <= n; ++i)
            if(!f[i])
                findPath(trace, i);
    }
    return 0;
}
