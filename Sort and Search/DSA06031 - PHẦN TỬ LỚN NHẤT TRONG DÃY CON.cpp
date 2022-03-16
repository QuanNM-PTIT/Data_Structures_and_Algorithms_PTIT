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
        deque<int> dq;
        cin >> n >> k;
        int a[n];
        for(int &i : a) cin >> i;
        dq.push_back(0);
        for(int i = 1; i < k; ++i)
        {
            while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
            dq.push_back(i);
        }
        cout << a[dq.front()] << ' ';
        for(int i = k; i < n; ++i)
        {
            while(!dq.empty() && a[dq.back()] < a[i]) dq.pop_back();
            dq.push_back(i);
            if(i - dq.front() < k) cout << a[dq.front()] << ' ';
            else
            {
                dq.pop_front();
                cout << a[dq.front()] << ' ';
            }
        }
        cout << endl;
    }
    return 0;
}

