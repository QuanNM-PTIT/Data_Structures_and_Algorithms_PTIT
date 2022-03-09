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
    int t = 1, n, num4, num7;
    cin >> t;
    while(t--)
    {
        cin >> n;
        num7 = n / 7;
        while(num7 >= 0)
        {
            if((n - num7 * 7) % 4 == 0)
            {
                num4 = (n - num7 * 7) >> 2;
                break;
            }
            --num7;
        }
        if(num7 >= 0)
        {
            while(num4--) cout << 4;
            while(num7--) cout << 7;
        }
        else cout << -1;
        cout << endl;
    }
    return 0;
}
