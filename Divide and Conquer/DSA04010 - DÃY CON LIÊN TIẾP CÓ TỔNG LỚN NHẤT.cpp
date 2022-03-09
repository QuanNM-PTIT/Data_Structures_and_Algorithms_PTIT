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

int main()
{
    faster();
    int t = 1, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n;
        vi a(n);
        bool check = 0;
        for(int &i : a)
        {
            cin >> i;
            if(i > 0) check = 1;
        }
        int M = -101;
        if(!check) for(int &i : a) M = max(M, i);
        else
        {
            int sum = 0;
            for(int i = 0; i < n; ++i)
            {
                sum += a[i];
                if(sum < 0) sum = 0;
                M = max(sum, M);
            }
        }
        cout << M << endl;
    }
    return 0;
}
