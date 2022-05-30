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

int l1[] = {0, 4, 1, 3, 8, 5, 2, 7, 9, 6};
int r1[] = {3, 0, 2, 7, 4, 1, 6, 8, 5, 9};
int l2[] = {1, 5, 2, 0, 4, 8, 6, 3, 7, 9};
int r2[] = {0, 2, 6, 3, 1, 5, 9, 7, 4, 8};

inline string Change(string &s, int a[])
{
    string res = "";
    for (int i = 0; i < 10; ++i)
        res += s[a[i]];
    return res;
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while (t--)
    {
        unordered_map<string, int> m;
        int ans = 1e9;
        string a, b = "1238004765";
        for (int i = 0; i < 10; ++i)
        {
            int x;
            cin >> x;
            a += to_string(x);
        }
        queue<pair<string, int>> q1, q2;
        q1.push({a, 0});
        q2.push({b, 0});
        pair<string, int> top;
        while (q1.size())
        {
            top = q1.front();
            q1.pop();
            pair<string, int> tmp = {Change(top.fi, l1), top.se + 1};
            if (!m[tmp.fi])
            {
                m[tmp.fi] = tmp.se;
                q1.push(tmp);
            }
            tmp.fi = Change(top.fi, r1);
            if (!m[tmp.fi])
            {
                m[tmp.fi] = tmp.se;
                q1.push(tmp);
            }
            if (tmp.se == 14)
                break;
        }
        while (q2.size())
        {
            top = q2.front();
            q2.pop();
            if (m[top.fi])
                ans = min(ans, m[top.fi] + top.se);
            pair<string, int> tmp = {Change(top.fi, l2), top.se + 1};
            q2.push(tmp);
            tmp.fi = Change(top.fi, r2);
            q2.push(tmp);
            if (tmp.se == 14)
                break;
        }
        cout << ans << endl;
    }
    return 0;
}
