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

int calc(vector<string> &vs, vi &a)
{
    int m = INT_MAX, M = INT_MIN, tmp;
    string s;
    for(string &i : vs)
    {
        s = "";
        for(int &j : a) s += i[j];
        tmp = stoi(s);
        m = min(m, tmp);
        M = max(M, tmp);
    }
    return M - m;
}

int main()
{
    faster();
    int t = 1, n, k;
    //cin >> t;
    string s;
    while(t--)
    {
        int res = INT_MAX;
        cin >> n >> k;
        vector<string> vs;
        while(cin >> s) vs.pb(s);
        vi a;
        for(int i = 0; i < k; ++i) a.pb(i);
        do
        {
            res = min(res, calc(vs, a));
        }
        while(next_permutation(all(a)));
        cout << res << endl;
    }
    return 0;
}
