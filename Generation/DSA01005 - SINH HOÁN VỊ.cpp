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

bool check[15] = {};
int n, a[15] = {};

void print()
{
    for (int i = 1; i <= n; ++i) cout << a[i];
    cout << ' ';
}
 
void Try(int i)
{
    for (int j = 1; j <= n; ++j)
    {
        if (!check[j])
        {
            a[i] = j;
            check[j] = 1;
            if(i == n) print();
            else Try(i + 1);
            check[j] = 0;
        }
    }
}

int main()
{
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n;
        Try(1);
        cout << endl;
    }
    return 0;
}
