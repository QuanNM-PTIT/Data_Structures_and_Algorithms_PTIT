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
    int t;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        int res = 0;
        stack<char> st;
        for(char &i : s)
        {
            if (st.empty() or i == '(')
                st.push(i);
            else if(st.top() == '(')
            {
                st.pop();
                res += 2;
            }
        }
        bool check = 0;
        while(st.sz)
        {
            if(st.top() == '(')
            {
                if(check)
                {
                    res += 2;
                    check = 0;
                }
                st.pop();
            }
            else
            {
                check = 1;
                st.pop();
            }
        }
        cout << res <<endl;
    }
    return 0;
}