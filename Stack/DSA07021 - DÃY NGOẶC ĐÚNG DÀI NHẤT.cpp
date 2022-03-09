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
    while(t--)
    {
        cin >> s;
        stack<int> st;
        st.push(-1);
        int res = -1;
        for(int i = 0; i < s.sz; ++i)
        {
            if(s[i] == '(') st.push(i);
            else
            {
                st.pop();
                if(st.empty()) st.push(i);
                else res = max(res, i - st.top());
            }
        }
        cout << res << endl;
    }
    return 0;
}
