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
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        int a[20005] = {}, s[20005] = {}, len;
        cin >> n;
        FOR(j, 1, n)
        {
            int x = (n << 1) - j + 1, delta = 1;
            for(int i = 2; i * i <= x; ++i)
            {
                while(x % i == 0)
                {
                    s[i] += delta;
                    x /= i;
                }
            }
            if(x != 1) s[x] += delta;
        }
        int st = n + 1;
        FOR(j, 1, st)
        {
            int x = j, delta = -1;
            for(int i = 2; i * i <= x; ++i)
            {
                while(x % i == 0)
                {
                    s[i] += delta;
                    x /= i;
                }
            }
            if(x != 1) s[x] += delta;
        }
        a[0] = len = 1;
        F(j, 1, 20005)
        {
            while(s[j]--)
            {
                int x = j;
                len += 5;
                F(i, 0, len) a[i] *= x;
                F(i, 0, len)
                {
                    a[i + 1] += a[i] / 10;
                    a[i] %= 10;
                }
                while(len > 0 && a[len - 1] == 0) --len;
            }
        }
        FORD(i, len - 1, 0) cout << a[i];
        cout << endl;
    }
    return 0;
}