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
    //cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        stack<char> st1, st2;
        for(char &i : s)
        {
            switch(i)
            {
                case '>':
                {
                    if(st2.sz)
                    {
                        st1.push(st2.top());
                        st2.pop();
                    }
                    break;
                }
                case '<':
                {
                    if(st1.sz)
                    {
                        st2.push(st1.top());
                        st1.pop();
                    }
                    break;
                }
                case '-':
                {
                    if(st1.sz)
                        st1.pop();
                    break;
                }
                default:
                    st1.push(i);
            }
        }
        while(st1.sz)
        {
            st2.push(st1.top());
            st1.pop();
        }
        while(st2.sz)
        {
            cout << st2.top();
            st2.pop();
        }
    }
    return 0;
}
