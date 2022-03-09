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

vi a = {0, 1, 2, 3, 4}, x(4);
int b[5];
vector<vector<int>> v1, v2;

void backtrack(int i = 0)
{
    for(int j = 0; j < 3; ++j)
    {
        x[i] = j;
        if(i == 3) v2.pb(x);
        else backtrack(i + 1);
    }
}

string solve()
{
    for(vector<int> &i : v1)
    {
        for(vector<int> &j : v2)
        {
            int res = b[i[0]];
            for(int z = 1; z < 5; ++z)
            {
                if(j[z - 1] == 0) res += b[i[z]];
                else if(j[z - 1] == 1) res -= b[i[z]];
                else res *= b[i[z]];
            }
            if(res == 23) return "YES\n";
        }
    }
    return "NO\n";
}

int main()
{
    faster();
    v1.pb(a);
    while(next_permutation(all(a))) v1.pb(a);
    backtrack();
    int t = 1;
    cin >> t;
    while(t--)
    {
        for(int i = 0; i < 5; ++i) cin >> b[i];
        cout << solve();
    }
    return 0;
}
