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

inline int binSearch(int n, int m, int s)
{
    int res = -1, mid, l = 1, r = s;
    while(l <= r)
    {
        mid = (l + r) >> 1;
        if((mid - mid / 7) * n >= s * m)
        {
            res = mid;
            r = mid - 1;
        }
        else l = mid + 1;
    }
    if(res != -1) res -= res / 7;
    return res;
}

int main()
{
    faster();
    int t = 1, n, m, s;
    cin >> t;
    while(t--)
    {
        cin >> n >> s >> m;
        cout << binSearch(n, m, s) << endl;
    }
    return 0;
}