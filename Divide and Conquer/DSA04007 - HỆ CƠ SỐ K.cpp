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

inline int cv(string &s, int &k)
{
    int res = 0;
    for(char &i : s) res = res * k + (i - '0');
    return res;
}

int main()
{
    faster();
    int t = 1, k;
    cin >> t;
    string a, b;
    while(t--)
    {
        cin >> k >> a >> b;
        int res = cv(a, k) + cv(b, k);
        stack<int> st;
        while(res)
        {
            st.push(res % k);
            res /= k;
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

