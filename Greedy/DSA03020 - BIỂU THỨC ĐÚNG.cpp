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
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        stack<char> st;
        int cnt = 0, res = 0;
        for(char &i : s)
        {
            if(st.empty())
            {
                st.push(i);
                cnt = 0;
            }
            else if(st.top() == '[' and i == ']')
            {
                cnt += 2;
                st.pop();
            }
            else if(st.top() == ']' and i == '[')
            {
                res += st.sz + cnt;
                st.pop();
            }
            else if(i == ']' and st.top() == ']') st.push(i);
            else if(i == '[') st.push(i);
        }
        cout << res << endl;
    }
    return 0;
}
