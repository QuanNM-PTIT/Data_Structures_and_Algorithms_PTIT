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
    int t = 1;
    cin >> t;
    deque<int> dq;
    string s;
    while(cin >> s)
    {
        if(s == "PUSHBACK")
        {
            cin >> t;
            dq.push_back(t);
        }
        else if(s == "PUSHFRONT")
        {
            cin >> t;
            dq.push_front(t);
        }
        else if(s == "PRINTFRONT")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.front() << endl;
        }
        else if(s == "POPFRONT" and dq.sz) dq.pop_front();
        else if(s == "PRINTBACK")
        {
            if(dq.empty()) cout << "NONE\n";
            else cout << dq.back() << endl;
        }
        else if(s == "POPBACK" and dq.sz) dq.pop_back();
    }
    return 0;
}
