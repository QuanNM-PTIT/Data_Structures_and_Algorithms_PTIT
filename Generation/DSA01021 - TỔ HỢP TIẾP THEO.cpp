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
    int t, n, k;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        int a[k + 1],b[k + 1], cnt = 0, idx;
        for(int i = 1;i <= k; i++)
        {
            cin >> b[i];
            a[i] = b[i];
        }
        idx = k;
        while(a[idx] == n - k + idx && idx > 0) idx--;
        if(idx < 1)
        {
            cout << k << endl;
        }
        else
        {
            a[idx]++;
            for(int j = idx + 1; j <= k; j++) a[j] = a[j - 1] + 1;
            for(int i = 1; i <= k; i++)
                for(int j = 1; j <= k; j++)
                    if(a[i] == b[j]) ++cnt;
            if(cnt == k) cnt = 0;
            cout << k - cnt << endl;
        }
    }
    return 0;
}
