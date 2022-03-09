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

ll cnt(string &s, int k)
{
    ll f[26] = {};
    for(char &i : s) ++f[i - 'A'];
    priority_queue<ll> pq;
    for(int i = 0; i < 26; ++i) pq.push(f[i]);
    ll tmp;
    while(k--)
    {
        tmp = pq.top();
        pq.pop();
        --tmp;
        pq.push(tmp);
    }
    ll sum = 0;
    while(!pq.empty())
    {
        tmp = pq.top();
        sum += tmp * tmp;
        pq.pop();
    }
    return sum;
}

int main()
{
    faster();
    int t = 1, k;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> k >> s;
        cout << cnt(s, k) << endl;
    }
    return 0;
}
