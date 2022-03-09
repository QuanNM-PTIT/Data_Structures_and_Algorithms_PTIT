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
    int t = 1, x, n, y;
    cin >> t;
    while(t--)
    {
        deque<int> q;
        cin >> n;
        while(n--)
        {
            cin >> x;
            if(x == 1) cout << q.sz << endl;
            else if(x == 2)
            {
                if(q.empty()) cout << "YES\n";
                else cout << "NO\n";
            }
            else if(x == 3)
            {
                cin >> y;
                q.push_back(y);
            }
            else if(x == 4 and q.sz) q.pop_front();
            else if(x == 5)
            {
                if(q.sz) cout << q.front() << endl;
                else cout << -1 << endl;
            }
            else if(x == 6)
            {
                if(q.sz) cout << q.back() << endl;
                else cout << -1 << endl;
            }
        }
    }
    return 0;
}