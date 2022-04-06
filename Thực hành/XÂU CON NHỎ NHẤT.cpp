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
    string s;
    cin >> t;
    while(t--)
    {
        cin >> s;
        bitset<260> bs;
        for(char &i : s)
            bs[i] = 1;
        int m[260] = {};
        int l, r, cnt;
        l = r = cnt = 0;
        int res = s.sz;
        while(r < s.sz)
        {
            if(!m[s[r]])
                ++cnt;
            ++m[s[r]];
            if(cnt == bs.count())
            {
                while(cnt == bs.count() and l < r)
                {
                    --m[s[l]];
                    if(!m[s[l]])
                        --cnt;
                    ++l;
                }
                res = min(res, r - l + 2);
            }
            ++r;
        }
        if(cnt == bs.count())
        {
            while(cnt == bs.count() and l < r)
            {
                --m[s[l]];
                if(!m[s[l]])
                    --cnt;
                ++l;
            }
            res = min(res, r - l + 2);
        }
        cout << res << endl;
    }
    return 0;
}