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
    vector<string> vs;
    vs.pb("66");
    vs.pb("88");
    queue<string> q;
    q.push("6");
    q.push("8");
    string s1, s2, top;
    while(vs.sz < 10005)
    {
        top = q.front();
        q.pop();
        s1 = top + '6';
        s2 = top + '8';
        q.push(s1);
        q.push(s2);
        reverse(all(s1));
        vs.pb(top + '6' + s1);
        reverse(all(s2));
        vs.pb(top + '8' + s2);
    }
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cout << vs[i] << ' ';
        cout << endl;
    }
    return 0;
}

