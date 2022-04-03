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

inline bool check(string s)
{
    int cnt = 0;
    for(char &i : s)
        cnt += i == '2';
    return cnt > (s.sz >> 1);
}

int main()
{
    faster();
    queue<string> q;
    q.push("1");
    q.push("2");
    vector<string> res;
    string top;
    while(res.sz < 1e3)
    {
        top = q.front();
        q.pop();
        if(check(top))
            res.pb(top);
        for(char i = '0'; i <= '2'; ++i)
            q.push(top + i);
    }
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cout << res[i] << ' ';
        cout << endl;
    }
    return 0;
}
