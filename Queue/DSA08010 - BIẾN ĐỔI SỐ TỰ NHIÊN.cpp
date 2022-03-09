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

inline int BFS(int n)
{
    unordered_map<int, int> m;
    if(n == 1) return 0;
    queue<int> q;
    q.push(n);
    int sqr, top;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        sqr = sqrt(top);
        for(int i = 2; i <= sqr; ++i)
        {
            if(top % i == 0 and !m[top / i])
            {
                if(top / i == 1) return m[top] + 1;
                m[top / i] = m[top] + 1;
                q.push(top / i);
            }
        }
        if(top - 1 == 1) return m[top] + 1;
        if(!m[top - 1])
        {
            m[top - 1] = m[top] + 1;
            q.push(top - 1);
        }
    }
    return -1;
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        cout << BFS(n) << endl;
    }
    return 0;
}
