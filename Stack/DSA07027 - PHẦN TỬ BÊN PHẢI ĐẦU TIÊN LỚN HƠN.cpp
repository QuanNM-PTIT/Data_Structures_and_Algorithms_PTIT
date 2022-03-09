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
        st.push(a[n - 1]);
        for(int i = n - 2; i >= 0; --i)
        {
            if(st.sz and a[i] < st.top())
            {
                res[i] = st.top();
                st.push(a[i]);
            }
            else
            {
                while(st.size() and a[i] >= st.top()) st.pop();
                if(st.sz) res[i] = st.top();
                else res[i] = -1;
                st.push(a[i]);
            }
        }
        for(int &i : res) cout << i << ' ';
        cout << endl;
    }
    return 0;
}