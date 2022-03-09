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
#define faster() ios_base::sync_with_stdio(0); cin.tie(NULL);cout.tie(NULL);
#define vi vector<int>
#define vll vector<ll>
#define all(x) (x).begin(), (x).end()
#define endl '\n'
 
int main()
{
    faster();
    int t = 1, n, k, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int a[n], f[n], sum = 0;
        cin >> a[0];
        f[0] = a[0];
        sum += a[0];
        for(int i = 1; i < n; ++i)
        {
            cin >> a[i];
            f[i] = f[i - 1] + a[i];
            sum += a[i];
        }
        bool check = 1;
        for(int i = 1; i < n; ++i)
        {
            if(f[i] - a[i] == sum - f[i])
            {
                cout << i + 1 << endl;
                check = 0;
                break;
            }
        }
        if(check) cout << -1 << endl;
    }
    return 0;
}
