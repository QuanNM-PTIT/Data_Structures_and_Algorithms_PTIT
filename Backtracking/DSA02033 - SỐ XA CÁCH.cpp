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

bool check(vi &a, int n)
{
    for(int i = 2; i <= n; ++i) if(abs(a[i] - a[i - 1]) == 1) return 0;
    return 1;
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        if(n < 4)
        {
            cout << endl;
            continue;
        }
        vi a(n + 1);
        for(int i = 1; i <= n; ++i) a[i] = i;
        while(next_permutation(a.begin() + 1, a.end()))
        {
            if(check(a, n))
            {
                for(int i = 1; i <= n; ++i) cout << a[i];
                cout << endl;
            }
        }
        cout << endl;
    }
    return 0;
}
