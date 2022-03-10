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
    int t = 1, n, s;
    //cin >> t;
    while(t--)
    {
        cin >> n >> s;
        if(s <= n * 9 and s)
        {
            stack<int> st;
            queue<int> q;
            while(s)
            {
                if(s > 9)
                {
                    st.push(9);
                    q.push(9);
                    s -= 9;
                }
                else
                {
                    st.push(s);
                    q.push(s);
                    break;
                }
            }
            if(st.sz < n and st.top() > 1)
            {
                int tmp = st.top();
                st.pop();
                st.push(tmp - 1);
                st.push(1);
            }
            int s = st.sz;
            cout << st.top();
            st.pop();
            while(s < n)
            {
                cout << 0;
                ++s;
            }
            while(st.sz)
            {
                cout << st.top();
                st.pop();
            }
            cout << ' ';
            s = q.sz;
            while(q.sz)
            {
                cout << q.front();
                q.pop();
            }
            while(s < n)
            {
                cout << 0;
                ++s;
            }
        }
        else cout << -1 << ' ' << -1;
        cout << endl;
    }
    return 0;
}