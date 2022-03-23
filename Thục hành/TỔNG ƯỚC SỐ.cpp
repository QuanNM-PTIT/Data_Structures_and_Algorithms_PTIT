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
    int N, a, b, cnt = 0;
    cin >> a >> b;
    N = b;
    vll div(N + 5, 1);
    for(int i = 2; i <= N; ++i)
        for(int j = i; j <= N; j += i)
            div[j] += i;
    for(int i = a; i <= b; ++i)
        cnt += (div[i] - i > i);
    cout << cnt;
    return 0;
}
