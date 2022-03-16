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

bool notPrime[205] = {};
int N = 200, n, s, p, st;
vi prime, tmp;
vector<vector<int>> res;

void sieve()
{
    int sqr = sqrt(N);
    for(int i = 2; i <= sqr; ++i)
        if(!notPrime[i])
            for(int j = i * i; j <= N; j += i)
                notPrime[j] = 1;
    for(int i = 2; i <= N; ++i) if(!notPrime[i]) prime.pb(i);
}

void Try(int i, int sum = 0)
{
    if(sum > s) return;
    if(sum == s)
    {
        if(tmp.sz == n) res.pb(tmp);
        return;
    }
    for(int j = i; j < prime.sz; ++j)
    {
        tmp.pb(prime[j]);
        Try(j + 1, sum + prime[j]);
        tmp.pop_back();
    }
}

int main()
{
    faster();
    sieve();
    int t;
    cin >> t;
    while(t--)
    {
        cin >> n >> p >> s;
        st = upper_bound(all(prime), p) - prime.begin();
        Try(st);
        cout << res.sz << endl;
        for(vector<int> &i : res)
        {
            for(int &j : i) cout << j << ' ';
            cout << endl;
        }
        tmp.clear();
        res.clear();
    }
    return 0;
}
