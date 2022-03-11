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
   int t = 1, n;
   cin >> t;
   while(t--)
   {
       cin >> n;
       vi a(n);
       for(int &i : a) cin >> i;
       vi dpL(n, 0), dpR(n, 0);
       for(int i = 0; i < n; ++i)
       {
           dpL[i] = a[i];
           for(int j = 0; j < i; ++j)
               if(a[i] > a[j]) dpL[i] = max(dpL[i], dpL[j] + a[i]);
       }
       for(int i = n - 1; ~i; --i)
       {
           dpR[i] = a[i];
           for(int j = n - 1; j > i; --j)
               if(a[i] > a[j]) dpR[i] = max(dpR[i], dpR[j] + a[i]);
       }
       int res = -1;
       for(int i = 0; i < n; ++i) res = max(res, dpL[i] + dpR[i] - a[i]);
       cout << res << endl;
   }
   return 0;
}
