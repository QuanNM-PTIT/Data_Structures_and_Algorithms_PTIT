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

vector<string> vs;
unordered_map<string, bool> m;

inline void Try(string s)
{
    stack<int> st;
    pair<int, int> p;
    vector<pair<int, int>> vp;
    for(int i = 0; i < s.sz; ++i)
    {
        if(s[i] == '(')
            st.push(i);
        else if(s[i] == ')')
        {
            p.fi = st.top();
            p.se = i;
            st.pop();
            vp.push_back(p);
        }
    }
    if(vp.empty())
        return;
    string tmp;
    for(pair<int, int> &i : vp)
    {
        tmp = s;
        tmp.erase(tmp.begin() + i.se);
        tmp.erase(tmp.begin() + i.fi);
        if(!m[tmp])
        {
            m[tmp] = 1;
            vs.pb(tmp);
            Try(tmp);
        }
    }
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        Try(s);
        sort(all(vs));
        for(string &i : vs)
            cout << i << endl;
    }
    return 0;
}

