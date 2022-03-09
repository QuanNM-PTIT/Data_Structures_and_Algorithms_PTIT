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

int n, k;
int a[105];
int sum;
bool check;

void Try(int i, int cur = 0)
{
    if(check) return;
    if(cur == sum)
    {
        check = 1;
        cout << "YES\n";
        return;
    }
    if(cur > sum) return;
    for(int j = i; j <= n; ++j) Try(j + 1, cur + a[j]);
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        sum = 0;
        check = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> a[i];
            sum += a[i];
        }
        if(sum & 1) cout << "NO\n";
        else
        {
            sum >>= 1;
            Try(1);
            if(!check) cout << "NO\n";
        }
    }
    return 0;
}
