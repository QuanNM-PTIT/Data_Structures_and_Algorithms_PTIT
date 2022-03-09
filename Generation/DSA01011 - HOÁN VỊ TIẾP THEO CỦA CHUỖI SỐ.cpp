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
    int cnt;
    while(t--)
    {
        cin >> cnt;
        cout << cnt << ' ';
        cin >> s;
        int i, j;
        i = s.sz - 2;
        while (i >= 0 && s[i] >= s[i + 1]) --i;
        if(i < 0)
        {
            cout << "BIGGEST" << endl;
            continue;
        }
        j = s.size() - 1;
        while(s[i] >= s[j]) j--;
        swap(s[i], s[j]);
        sort(s.begin() + i + 1, s.end());
        cout << s << endl;
    }
    return 0;
}
