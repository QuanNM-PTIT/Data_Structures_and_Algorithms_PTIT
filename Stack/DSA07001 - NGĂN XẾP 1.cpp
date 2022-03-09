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

int main()
{
    faster();
    stack<int> st;
    int n;
    string s;
    while(cin >> s)
    {
        if(s == "pop" and st.sz) st.pop();
        else if(s == "push")
        {
            cin >> n;
            st.push(n);
        }
        else
        {
            if(st.empty()) cout << "empty" << endl;
            else
            {
                stack<int> tmp;
                while(st.sz)
                {
                    tmp.push(st.top());
                    st.pop();
                }
                while(tmp.sz)
                {
                    cout << tmp.top() << ' ';
                    st.push(tmp.top());
                    tmp.pop();
                }
                cout << endl;
            }
        }
    }
    return 0;
}
