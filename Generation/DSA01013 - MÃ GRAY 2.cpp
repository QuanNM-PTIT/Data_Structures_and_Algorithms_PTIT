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
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        cout << s[0];
        int tmp = s[0] - '0', x;
        for(int i = 1; i < s.sz; ++i)
        {
            x = s[i] - '0';
            if(x != tmp)
            {
                tmp = 1;
                cout << tmp;
            }
            else
            {
                tmp = 0;
                cout << tmp;
            }
        }
        cout << endl;
    }
    return 0;
}
