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
    int t = 1, n, x;
    cin >> t;
    string s;
    priority_queue<int> pq;
    while(t--)
    {
        cin >> n >> s;
        int f[30] = {};
        for(char &i : s) ++f[i - 'A'];
        for(int i = 0; i < 26; ++i) if(f[i]) pq.push(f[i]);
        while(n--)
        {
            x = pq.top();
            pq.pop();
            --x;
            pq.push(x);
        }
        ll res = 0;
        while(pq.sz)
        {
            res += 1LL * pq.top() * pq.top();
            pq.pop();
        }
        cout << res << endl;
    }
    return 0;
}