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
 
int degree(char c)
{
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

ll calc(ll a, ll b, char c)
{
    switch(c)
    {
        case '+':
            return a + b;
        case '-':
            return a - b;
        case '*':
            return a * b;
        default:
            return a / b;
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        stack <ll> num;
        stack <char> op;
        ll val, val1, val2;
        char top;
        for(int i = 0; i < s.sz; ++i)
        {
            if(s[i] == '(')
                op.push(s[i]);
            else if(isdigit(s[i]))
            {
                val = 0;
                while(i < s.sz and isdigit(s[i]))
                {
                    val = val * 10 + s[i] - '0';
                    ++i;
                }
                num.push(val);
                --i;
            }
            else if(s[i] == ')')
            {
                while(op.sz and op.top() != '(')
                {
                    val2 = num.top();
                    num.pop();
                    val1 = num.top();
                    num.pop();
                    char top = op.top();
                    op.pop();
                    num.push(calc(val1, val2, top));
                }
                if(op.sz)
                   op.pop();
            }
            else
            {
                while(op.sz and degree(op.top()) >= degree(s[i]))
                {
                    val2 = num.top();
                    num.pop();
                    val1 = num.top();
                    num.pop();
                    top = op.top();
                    op.pop();
                    num.push(calc(val1, val2, top));
                }
                op.push(s[i]);
            }
        }
        while(op.sz)
        {
            val2 = num.top();
            num.pop();
            val1 = num.top();
            num.pop();
            top = op.top();
            op.pop();
            num.push(calc(val1, val2, top));
        }
        cout << num.top() << endl;
    }
    return 0;
}