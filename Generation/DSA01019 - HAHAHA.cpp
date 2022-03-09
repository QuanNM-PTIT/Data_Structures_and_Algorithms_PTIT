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

int n;
vector<char> vc;
char a[2] = {'A', 'H'};

void print()
{
    for(int i = 1; i <= n; ++i) cout << vc[i];
    cout << endl;
}

void Try(int i)
{
    for(int j = 0; j < 2; ++j)
    {
        if(vc[i - 1] == 'H' and j == 1) continue;
        vc[i] = a[j];
        if(i == n - 1) print();
        else Try(i + 1);
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
        if(n == 2)
        {
            cout << "HA\n";
            continue;
        }
        vc.resize(n + 1);
        vc[1] = 'H';
        vc[n] = 'A';
        Try(2);
    }
    return 0;
}
