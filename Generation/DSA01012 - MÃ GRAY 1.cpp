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
    int t = 1, n, k, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int t = pow(2, n);
        t >>= 1;
        vector<string> s(pow(2, n));
        while(t)
        {
            F(i, 0, t) s[i] += "0";
            int tmp = t * 2;
            F(i, t, tmp) s[i] += "1";
            t >>= 1;
        }
        t = pow(2, n);
        t >>= 1;
        int move = 1;
        while(t != 1)
        {
            string tmp = "";
            F(i, 0, t) tmp += s[i][move];
            int cnt = pow(2, n) / t - 1;
            int k = t;
            while(cnt--)
            {
                if(cnt & 1)
                {
                    int j = 0;
                    for(int i = k; i <= k + tmp.length() - 1; ++i)
                    {
                        s[i] += tmp[j];
                        ++j;
                    }
                }
                else
                {
                    int j = tmp.length() - 1;
                    for(int i=k; i <= k + tmp.length() - 1; ++i)
                    {
                        s[i] += tmp[j];
                        --j;
                    }
                }
                k += tmp.length();
            }
            t >>= 1;
            ++move;
        }
        for(string i : s) cout << i << ' ';
        cout << endl;
    }
    return 0;
}

