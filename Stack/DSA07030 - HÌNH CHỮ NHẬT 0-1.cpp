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
    int n, m;
    int a[505][505];
    while(t--)
    {
        cin >> n >> m;
        for(int i = 0; i < n; ++i)
            for(int j = 0; j < m; ++j)
                cin >> a[i][j];
        for(int i = 0; i < m; ++i)
            for(int j = 1; j < n; ++j)
                a[j][i] = (a[j - 1][i] + 1) * a[j][i];
        int res = 0;
        for(int i = 0; i < n; ++i)
        {
            stack<int> st;
            int x[m], y[m];
            st.push(-1);
            for(int j = 0; j < m; ++j)
            {
                while(st.sz > 1 and a[i][st.top()] >= a[i][j])
                    st.pop();
                x[j] = st.top() + 1;
                st.push(j);
            }
            st = {};
            st.push(m);
            for(int j = m - 1; ~j; --j)
            {
                while(st.sz > 1 and a[i][st.top()] >= a[i][j])
                    st.pop();
                y[j] = st.top() - 1;
                st.push(j);
            }
            for(int j = 0; j < m; ++j)
                res = max(res, (y[j] - x[j] + 1) * a[i][j]);
        }
        cout << res << endl;
    }
    return 0;
}

