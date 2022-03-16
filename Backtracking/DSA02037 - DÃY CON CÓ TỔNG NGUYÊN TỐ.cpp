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

bool notPrime[1505];
int N = 1500, sqr = sqrt(N), n;
int a[20];
vector<vector<int>> res;
vi v;

inline void Try(int i, int sum = 0)
{
    if(!notPrime[sum]) res.pb(v);
    if(i > n) return;
    for(int j = i; j <= n; ++j)
    {
        v.pb(a[j]);
        Try(j + 1, sum + a[j]);
        v.pop_back();
    }
}

int main()
{
    faster();
    notPrime[0] = notPrime[1] = 1;
    for(int i = 2; i <= sqr; ++i)
        if(!notPrime[i])
            for(int j = i * i; j <= N; j += i)
                notPrime[j] = 1;
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 1; i <= n; ++i) cin >> a[i];
        sort(a + 1, a + 1 + n, greater<int>());
        Try(1);
        vector<string> vs;
        sort(all(res));
        for(auto &i : res)
        {
            for(int &j : i) cout << j << ' ';
            cout << endl;
        }
        v.clear();
        res.clear();
    }
    return 0;
}