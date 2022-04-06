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
    int t;
    cin >> t;
    ll n;
    while(t--)
    {
        cin >> n;
        if(n < 10)
        {
            cout << n << endl;
            continue;
        }
        stack<int> st;
        int i = 9;
        while(n > 1 and i > 1)
        {
            while(n % i == 0)
            {
                st.push(i);
                n /= i;
            }
            --i;
        }
        if(st.empty() or n > 9)
        {
            cout << -1 << endl;
            continue;
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
