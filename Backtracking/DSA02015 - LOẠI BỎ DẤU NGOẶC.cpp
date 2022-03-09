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

bool check(string s)
{
    if(s.empty()) return 0;
    if(s.sz == 1 && isalpha(s[0])) return 0;
    int cnt = 0;
    for(char i : s)
    {
        if(i == '(') ++cnt;
        else if(i == ')') --cnt;
        if(cnt < 0) return 0;
    }
    return !cnt;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s, tmp;
    cin.ignore();
    while(t--)
    {
        cin >> s;
        vector<string> ans;
        unordered_map<string, bool> m;
        queue<string> q;
        m[s] = 1;
        q.push(s);
        bool ok = 0;
        while(q.sz)
        {
            string s = q.front();
            q.pop();
            if(check(s))
            {
                ans.pb(s);
                ok = 1;
            }
            if(ok) continue;
            for(int i = 0; i < s.sz; ++i)
            {
                if(isalnum(s[i])) continue;
                tmp = s.substr(0, i) + s.substr(i + 1);
                if(!m[tmp])
                {
                    m[tmp] = 1;
                    q.push(tmp);
                }
            }
        }
        if(!ok) cout << -1;
        else
        {
            sort(all(ans));
            for(string i : ans) cout << i << ' ';
        }
        cout << endl;
    }
    return 0;
}