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

void push(vector<int> &v1, vector<string> &ans)
{
    vi v = v1;
    sort(v.begin(), v.end(), greater<int>());
    string s = "(";
    int size = v.sz - 1;
    F(i, 0, size)
    {
        s += to_string(v[i]);
        s += " ";
    }
    s += to_string(v[size]) + ")";
    ans.pb(s);
}

void Try(vi &v, int i, int n, vector<string> &ans)
{
    if (!n) push(v, ans);
    for (int j = n; j >= i; --j)
    {
        v.push_back(j);
        Try(v, j, n - j, ans);
        v.pop_back();
    }
}

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi v;
        vector<string> ans;
        Try(v, 1, n, ans);
        sort(ans.begin(), ans.end(), greater<string>());
        if(n == 10)
        {
            cout << "(10) ";
            ans.erase(ans.begin() + 40);
        }
        for(string i : ans) cout << i << ' ';
        cout << endl;
    }
    return 0;
}
