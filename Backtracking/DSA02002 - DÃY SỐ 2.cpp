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
    int t = 1, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        queue<int> q;
        stack<string> st;
        for(int i = 0; i < n; ++i)
        {
            cin >> x;
            q.push(x);
        }
        for(int i = 1; i <= n; ++i)
        {
            string s = "";
            s += '[';
            for(int j = n - i; j >= 0; --j)
            {
                x = q.front();
                s += to_string(x);
                if(j) s += ' ';
                q.pop();
                x += q.front();
                if(j) q.push(x);
            }
            s += "] ";
            st.push(s);
        }
        while(st.sz)
        {
            cout << st.top();
            st.pop();
        }
        cout << endl;
    }
    return 0;
}
