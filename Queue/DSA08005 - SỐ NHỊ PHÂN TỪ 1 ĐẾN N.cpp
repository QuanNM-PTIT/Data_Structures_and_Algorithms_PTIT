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
    int t = 1, x, n;
    stack<int> st;
    vector<string> v(10005);
    string s;
    for(int i = 1; i <= 1e4; ++i)
    {
        s = "";
        x = i;
        while(x)
        {
            st.push(x & 1);
            x >>= 1;
        }
        while(st.sz)
        {
            s += to_string(st.top());
            st.pop();
        }
        v[i] = s;
    }
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1 ; i<= n; ++i) cout << v[i] << ' ';
        cout << endl;
    }
    return 0;
}
