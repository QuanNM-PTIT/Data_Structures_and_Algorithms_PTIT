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

inline string calc(string s)
{
    stack<char> st1, st2;
    s = '+' + s;
    st2.push('+');
    for(char &i : s)
    {
        if(isalpha(i)) st1.push(i);
        else
        {
            if(i == '+' or i == '-')
            {
                if(st2.top() == '+') st1.push(i);
                else st1.push((i == '+') ? '-' : '+');
            }
            if(i == '(') st2.push(st1.top());
            else if(i == ')') st2.pop();
        }
    }
    string res = "";
    while(st1.sz > 1)
    {
        res = st1.top() + res;
        st1.pop();
    }
    return res;
    
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        cout << calc(s) << endl;
    }
    return 0;
}
