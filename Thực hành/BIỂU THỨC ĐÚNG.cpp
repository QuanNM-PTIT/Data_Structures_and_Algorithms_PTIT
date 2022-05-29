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

inline bool check(string &s)
{
    stack<char> st;
    for(char &i : s)
    {
        if(i == '(')
            st.push(i);
        else
        {
            if(st.empty())
                return 0;
            st.pop();
        }
    }
    return st.empty();
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        string tmp;
        cin >> tmp;
        string s = "";
        for(char &i : tmp)
            if(i == ')' or i == '(')
                s += i;
        if(!check(s))
        {
            cout << -1 << endl;
            continue;
        }
        int cnt = 0, res = 0;
        for(char &i : s)
        {
            if(i == '(')
            {
                ++cnt;
                res = max(res, cnt);
            }
            else
                --cnt;
        }
        cout << res << endl;
    }
    return 0;
}
