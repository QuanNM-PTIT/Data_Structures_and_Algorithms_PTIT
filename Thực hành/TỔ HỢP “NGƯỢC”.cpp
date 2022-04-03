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

int n, k;
stack<string> st;
int a[25];

void Try(int i, int idx = 1)
{
    for(int j = i; j <= n; ++j)
    {
        a[idx] = j;
        if(idx == k)
        {
            string s = "";
            for(int z = 1; z <= k; ++z)
                s += to_string(a[z]) + ' ';
            st.push(s);
        }
        else
            Try(j + 1, idx + 1);
    }
}

int main()
{
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        Try(1);
        while(st.sz)
        {
            cout << st.top() << endl;
            st.pop();
        }
    }
    return 0;
}
