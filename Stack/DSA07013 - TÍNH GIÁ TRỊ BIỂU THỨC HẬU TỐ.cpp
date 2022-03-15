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
    cin >> t;
    string s;
    ll a, b;
    while(t--)
    {
        cin >> s;
        stack<ll> st;
        for(char &i : s)
        {
            if(isdigit(i)) st.push(i - '0');
            else
            {
                b = st.top();
                st.pop();
                a = st.top();
                st.pop();
                switch(i)
                {
                    case '+':
                    {
                        st.push(a + b);
                        break;
                    }
                    case '-':
                    {
                        st.push(a - b);
                        break;
                    }
                    case '*':
                    {
                        st.push(a * b);
                        break;
                    }
                    default:
                    {
                        st.push(a / b);
                        break;
                    }
                }
            }
        }
        cout << st.top() << endl;
    }
    return 0;
}
