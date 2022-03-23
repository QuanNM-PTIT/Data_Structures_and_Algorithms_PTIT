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

char c, dc;
string s;

inline bool check(vi &v)
{
    s = "";
    int cnt0 = 0, cnt1 = 0;
    int max1 = 0, max0 = 0;
    for(int &i : v)
    {
        if(i)
        {
            s += c;
            max0 = max(max0, cnt0);
            cnt0 = 0;
            ++cnt1;
        }
        else
        {
            s += dc;
            max1 = max(max1, cnt1);
            cnt1 = 0;
            ++cnt0;
        }
    }
    max0 = max(max0, cnt0);
    max1 = max(max1, cnt1);
    return (max1 > max0 and max1 >= 5);
}

int main()
{
    faster();
    int t = 1, n, MAX;
    cin >> t;
    while(t--)
    {
        cin >> n >> c;
        if(c == 'X')
            dc = 'O';
        else
            dc = 'X';
        MAX = 1 << n;
        vector<vi> v;
        for(int i = 31; i < MAX; ++i)
        {
            vi tmp;
            for(int j = n - 1; ~j; --j)
                tmp.pb((i >> j) & 1);
            v.pb(tmp);
        }
        vector<string> vs;
        for(vector<int> &i : v)
        {
            if(check(i))
                vs.pb(s);
        }
        sort(all(vs));
        for(string &i : vs)
            cout << i << endl;
    }
    return 0;
}
