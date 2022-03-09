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
    string s;
    cin >> t;
    cin.ignore();
    while(t--)
    {
        getline(cin, s);
        stringstream ss(s);
        stack<string> st;
        while(ss >> s) st.push(s);
        while(st.sz)
        {
            cout << st.top() << ' ';
            st.pop();
        }
        cout << endl;
    }
    return 0;
}
