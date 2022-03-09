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

bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.fi < b.fi;
}

int main()
{
    faster();
    int t = 1, n;
    //cin >> t;
    while(t--)
    {
        int cnt = 1;
        cin >> n;
        vector<int> v(n);
        for(int &i : v) cin >> i;
        for(int i = 0; i < n - 1; ++i)
        {
            bool notSwap = 1;
            for(int j = 0; j < n - i - 1; ++j)
                if(v[j] > v[j + 1])
                {
                    swap(v[j], v[j + 1]);
                    notSwap = 0;
                }
            if(notSwap) break;
            cout << "Buoc " << cnt++ << ": ";
            for(int i : v) cout << i << ' ';
            cout << endl;
        }
        cout << endl;
    }
    return 0;
}
