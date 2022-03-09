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

int res = 0;
string s;
int f[3] = {};

inline void solve(int a, int b, int idx, char c)
{
    for(int i = a; i < b; ++i)
    {
        if(s[i] == c)
        {
            swap(s[idx], s[i]);
            ++res;
            return;
        }
    }
}

int main()
{
    faster();
    int t = 1, n;
    //cin >> t;
    while(t--)
    {
        cin >> n >> s;
        for(char &i : s)
        {
            if(i == 'X') ++f[0];
            else if(i == 'T') ++f[1];
            else ++f[2];
        }
        for(int i = 0; i < f[0]; ++i)
        {
            if(s[i] == 'T') solve(f[0], n, i, 'X');
            else if(s[i] == 'D')
            {
                for(int j = n - 1; j >= f[0]; --j)
                {
                    if(s[j] == 'X')
                    {
                        swap(s[i], s[j]);
                        ++res;
                        break;
                    }
                }
            }
       }
        for(int i = f[0]; i < f[0] + f[1]; ++i) if(s[i] == 'D') solve(f[0] + f[1], n, i, 'T');
        cout << res;
    }
    return 0;
}
