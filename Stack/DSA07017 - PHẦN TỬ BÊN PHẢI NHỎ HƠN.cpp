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
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n];
        int res[n];
        for(int &i : a) cin >> i;
        res[n - 1] = -1;
        stack<int> st;
        st.push(n - 1);
        for(int i = n - 2; i >= 0; --i)
        {
            if(st.sz and a[i] < a[st.top()])
            {
                res[i] = st.top();
                st.push(i);
            }
            else
            {
                while(st.sz and a[i] >= a[st.top()]) st.pop();
                if(st.sz) res[i] = st.top();
                else res[i] = -1;
                st.push(i);
            }
        }
        stack<int> st2;
        int ans[n];
        ans[n - 1] = -1;
        st2.push(n - 1);
        for(int i = n - 2; i >= 0; --i)
        {
            if(st2.sz and a[i] > a[st2.top()])
            {
                ans[i] = st2.top();
                st2.push(i);
            }
            else
            {
                while(st2.sz and a[i] <= a[st2.top()]) st2.pop();
                if(st2.sz) ans[i] = st2.top();
                else ans[i] = -1;
                st2.push(i);
            }
        }
        for(int i = 0; i < n; ++i)
        {
            if(res[i] != -1 and ans[res[i]] != -1) cout << a[ans[res[i]]] << ' ';
            else cout << -1 << ' ';
        }
        cout << endl;
    }
    return 0;
}
