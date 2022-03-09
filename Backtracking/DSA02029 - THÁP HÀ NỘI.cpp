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

void Try(int n, char a, char b, char c)
{
    if(n==1)
    {
        cout << a << " -> " << c << endl;
        return;
    }
    Try(n - 1, a, c, b);
    Try(1, a, b, c);
    Try(n - 1, b, a, c);
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        int n;
        cin >> n;
        Try(n, 'A', 'B', 'C');
    }
    return 0;
}
