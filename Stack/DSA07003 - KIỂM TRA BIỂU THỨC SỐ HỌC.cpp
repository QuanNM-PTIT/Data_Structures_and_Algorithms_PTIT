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

string calc(string &s)
{
    stack<char> st;
    bool check;
    char cur;
    for(char &i : s)
    {
        if(i == ')')
        {
            check = 0;
            cur = st.top();
            st.pop();
            while(cur != '(')
            {
                if(cur == '+' or cur == '-' or  cur == '*' or cur == '/') check = 1;
                cur = st.top();
                st.pop();
            }
            if(!check) return "Yes";
        }
        else st.push(i);
    }
    return "No";
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
        cout << calc(s) << endl;
    }
    return 0;
}