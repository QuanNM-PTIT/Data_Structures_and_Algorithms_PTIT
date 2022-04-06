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
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        string s = "";
        for(int i = 1; i <= n; ++i)
            s += (char) i + '0';
        stack<string> st;
        st.push(s);
        while(next_permutation(all(s)))
            st.push(s);
        while(st.sz > 1)
        {
            cout << st.top() << ',';
            st.pop();
        }
        cout << st.top() << endl;
    }
    return 0;
}
