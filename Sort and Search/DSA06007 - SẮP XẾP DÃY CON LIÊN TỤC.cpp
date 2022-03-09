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
    int t, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vector<int> v1(n), v2(n);
        for(int i = 0; i < n; ++i) cin >> v1[i];
        v2 = v1;
        sort(all(v1));
        for(int i = 0; i < n; ++i)
        {
            if(v1[i] != v2[i])
            {
                cout << i + 1 << ' ';
                break;
            }
        }
        for(int i = n - 1; i; --i)
        {
            if(v1[i] != v2[i])
            {
                cout << i + 1 << endl;
                break;
            }
        }
    }
    return 0;
}
