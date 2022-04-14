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

bitset<100005> notPrime;

inline void sieve()
{
    int N = 1e5;
    int sqr = sqrt(N);
    for(int i = 2; i <= sqr; ++i)
        if(!notPrime[i])
            for(int j = i * i; j <= N; j += i)
                notPrime[j] = 1;
}

inline int BFS(string &a, string &b)
{
    queue<string> q;
    string top;
    unordered_map<string, int> m;
    q.push(a);
    m[a] = 1;
    int tmp;
    string ori;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        for(int i = 0; i < 4; ++i)
        {
            ori = top;
            for(char j = '0'; j <= '9'; ++j)
            {
                top[i] = j;
                tmp = stoi(top);
                if(!notPrime[tmp] and !m[top] and tmp >= 1000)
                {
                    if(top == b)
                        return m[ori];
                    m[top] = m[ori] + 1;
                    q.push(top);
                }
                top = ori;
            }
        }
    }
    return -1;
}

int main()
{
    faster();
    sieve();
    int t;
    cin >> t;
    string a, b;
    while(t--)
    {
        cin >> a >> b;
        if(a == b)
            cout << 0 << endl;
        else
            cout << BFS(a, b) << endl;
    }
    return 0;
}
