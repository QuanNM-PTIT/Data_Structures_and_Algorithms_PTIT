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
    int t = 1;
    string s, tmp;
    cin >> t;
    while(t--)
    {
        cin >> s;
        stack<string> st;
        for(int i = s.sz - 1; i >= 0; --i)
        {
            tmp = "";
            if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/')
            {
                tmp += st.top();
                st.pop();
                tmp += st.top() + s[i];
                st.pop();
                st.push(tmp);
            }
            else st.push(tmp + s[i]);
        }
        while(st.sz)
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}
