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
    int t;
    cin >> t;
    int v, e, u, x, y, z;
    while(t--)
    {
        cin >> v >> e >> u;
        vector<pair<int, int>> a[v + 5];
        while(e--)
        {
            cin >> x >> y >> z;
            a[x].pb({y, z});
            a[y].pb({x, z});
        }
        int dist[v + 5];
        for(int i = 1; i <= v; ++i)
            dist[i] = INT_MAX;
        dist[u] = 0;
        priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> pq;
        pq.push({0, u});
        pair<int, int> top;
        while(pq.sz)
        {
            top = pq.top();
            pq.pop();
            if(top.fi <= dist[top.se])
            {
                for(pair<int, int> &i : a[top.se])
                {
                    if(dist[i.fi] > dist[top.se] + i.se)
                    {
                        dist[i.fi] = dist[top.se] + i.se;
                        pq.push({dist[i.fi], i.fi});
                    }
                }
            }
        }
        for(int i = 1; i <= v; ++i)
            cout << dist[i] << ' ';
        cout << endl;
    }
    return 0;
}
