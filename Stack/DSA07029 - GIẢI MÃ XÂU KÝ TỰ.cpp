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
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        stack<char> st;
        string num, tmp, a, ans;
        ans = "";
        for(char &i : s)
        {
            if(i == ']')
            {
                num = tmp = "";
                while(st.sz and st.top() != '[')
                {
                    tmp += st.top();
                    st.pop();
                }
                if(st.sz)
                    st.pop();
                while(st.sz and isdigit(st.top()))
                {
                    num = st.top() + num;
                    st.pop();
                }
                a = "";
                if(num == "")
                    num = "1";
                int limit = stoi(num);
                for(int j = 1; j <= limit; ++j)
                    a += tmp;
                for(int j = a.sz - 1; ~j; --j)
                    st.push(a[j]);
            }
            else
                st.push(i);
        }
        while(st.sz)
        {
            ans = st.top() + ans;
            st.pop();
        }
        cout << ans << endl;
    }
    return 0;
}