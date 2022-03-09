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

ll prime[] = {2, 2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31}, ans;
int n;

void Try(int i, ll a = 1, ll b = 1)
{
    if(b > n) return;
    if(b == n) ans = min(ans, a);
    ll j = 1;
    while(a * prime[i] <= ans)
    {
        a *= prime[i];
        Try(i + 1, a, b * (j + 1));
        ++j;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ans = 1e18;
        Try(1);
        cout << ans << endl;
    }
    return 0;
}