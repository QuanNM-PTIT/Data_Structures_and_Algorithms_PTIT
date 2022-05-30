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

string s, e;

inline void BFS(unordered_set<string> &mySet)
{
    queue<string> q;
    q.push(s);
    int ans = 1;
    string u;
    char ori;
    while(q.sz)
    {
        ++ans;
        queue<string> tmp = q;
        while(tmp.sz)
        {
            u = tmp.front();
            tmp.pop();
            q.pop();
            for(int i = 0; i < u.sz; ++i)
            {
                ori = u[i];
                for(char j = 'A'; j <= 'Z'; ++j)
                {
                    u[i] = j;
                    if(u == e)
                    {
                        cout << ans << endl;
                        return;
                    }
                    if(mySet.find(u) != mySet.end())
                    {
                        q.push(u);
                        mySet.erase(u);
                    }
                }
                u[i] = ori;
            }
        }
    }
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    string x;
    while(t--)
    {
        cin >> n >> s >> e;
        unordered_set<string> mySet;
        while(n--)
        {
            cin >> x;
            mySet.insert(x);
        }
        if(s == e)
        {
            cout << 1 << endl;
            continue;
        }
        BFS(mySet);
    }
    return 0;
}