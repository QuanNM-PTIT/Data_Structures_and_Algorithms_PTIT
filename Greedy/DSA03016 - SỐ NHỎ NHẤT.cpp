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
    int t = 1, s, d;
    cin >> t;
    while(t--)
    {
        cin >> s >> d;
        stack<int> st;
        if(d == 1 && s == 0) cout << 0;
        if(s == 0 || d * 9 < s) cout << -1;
        else
        {
            --s;
            while(d--)
            {
                if(s >= 9)
                {
                    st.push(9);
                    s -= 9;
                }
                else if (s > 0)
                {
                    st.push(s);
                    s = 0;
                }
                else st.push(0);
            }
            cout << st.top() + 1;
            st.pop();
            while (!st.empty())
            {
                cout << st.top();
                st.pop();
            }
        }
        cout << endl;
    }
    return 0;
}
