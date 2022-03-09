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
        vi a(n + 5), c(n + 5);
        stack<int> st;
        for(int i = 1; i <= n; ++i) cin >> c[i];
        for(int i = 1; i <= n; ++i)
        {
            while(st.sz && c[i] >= c[st.top()]) st.pop();
            if(st.empty()) a[i] = 0;
            else a[i] = st.top();
            st.push(i);
        }
        for(int i = 1; i <= n; ++i) cout << i - a[i] << ' ';
        cout << endl;
    }
    return 0;
}
