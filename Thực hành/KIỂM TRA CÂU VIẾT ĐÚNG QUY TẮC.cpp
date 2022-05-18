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

inline string check(string &s)
{
    stack<char> st;
    for(char &i : s)
    {
        if(i == '(' or i == '[')
            st.push(i);
        if(i == ')')
        {
            if(st.sz and st.top() == '(')
                st.pop();
            else
                return "NO";
        }
        else if(i == ']')
        {
            if(st.sz and st.top() == '[')
                st.pop();
            else
                return "NO";
        }
    }
    if(st.empty())
        return "YES";
    return "NO";
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        cout << check(s) << endl;
    }
    return 0;
}
