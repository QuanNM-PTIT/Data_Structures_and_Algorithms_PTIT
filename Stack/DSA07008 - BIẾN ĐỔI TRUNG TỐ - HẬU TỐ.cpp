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

int degree(char c)
{
    if(c == '^') return 5;
    if(c == '*' || c == '/') return 4;
    if(c == '+' || c == '-') return 3;
    return 2;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        string res = "";
        cin >> s;
        stack<char> st;
        for(int i = 0; i < s.length(); i++)
        {
            if(isalpha(s[i])) res += s[i];
            else if(s[i] == '(') st.push(s[i]);
            else if(s[i] == ')')
            {
                while(st.size() && st.top() != '(')
                {
                    res += st.top();
                    st.pop();
                }
                st.pop();
            }
            else if(s[i] == '+' || s[i] == '-' || s[i] == '*' || s[i] == '/' || s[i] == '^')
            {
                while(st.size() && degree(st.top()) >= degree(s[i]))
                {
                    res += st.top();
                    st.pop();
                }
                st.push(s[i]);
            }
        }
        while(st.size())
        {
            if(st.top() != '(') res += st.top();
            st.pop();
        }
        cout << res << endl;
    }
    return 0;
}
