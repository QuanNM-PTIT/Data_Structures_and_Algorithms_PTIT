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
    //cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        int cnt = 0, res = 0;
        stack<pair<char, int>> st;
        st.push({'*', 0});
        for(char &i : s)
        {
            if(st.sz and ((i == ')' and st.top().fi == '(') or (i == ']' and  st.top().fi == '[')))
            {
                st.pop();
                if(st.sz)
                    res = max(res, cnt - st.top().se);
            }
            else
            {
                cnt += i == '[';
                st.push({i, cnt});
            }
        }
        cout << res;
    }
    return 0;
}

