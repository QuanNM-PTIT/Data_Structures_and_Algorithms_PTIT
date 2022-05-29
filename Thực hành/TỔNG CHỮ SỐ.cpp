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

string s;
ll n;
int k;

int calcSumDigit()
{
    int Sum = 0;
    for(char &i : s)
        Sum += i - '0';
    return Sum;
}

void bienDoi()
{
    int Sum = 0;
    for(int i = 1; i < s.size(); ++i)
    {
        Sum += s[i] - '0';
        if(Sum > k)
        {
            int idx = i - 1;
            while(s[idx] == '9')
                --idx;
            ++s[idx];
            for(int j = idx + 1; j < s.size(); ++j)
                s[j] = '0';
            break;
        }
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> n >> k;
        s = '0' + to_string(n);
        while(calcSumDigit() > k)
            bienDoi();
        cout << stoll(s) - n << endl;
    }
    return 0;
}
