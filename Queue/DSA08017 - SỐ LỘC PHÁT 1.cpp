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
    int t = 1, n;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> n;
        deque<string> res;
        queue<string> q;
        q.push("6");
        q.push("8");
        res.push_back("6");
        res.push_back("8");
        while(q.front().sz < n)
        {
            queue<string> tmp;
            while(q.sz)
            {
                res.push_back(q.front() + '6');
                res.push_back(q.front() + '8');
                tmp.push(q.front() + '6');
                tmp.push(q.front() + '8');
                q.pop();
            }
            q = tmp;
        }
        while(res.sz)
        {
            cout << res.back() << ' ';
            res.pop_back();
        }
        cout << endl;
    }
    return 0;
}
