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
    int t, n, x, sum;
    string res;
    cin >> t;
    while(t--)
    {
        cin >> n;
        priority_queue <int> pq;
        priority_queue <int, vector<int>, greater<int>> q1, q2;
        sum = 0;
        for(int i = 0; i < n; i++)
        {
            cin >> x;
            pq.push(x);
            sum += x;
            if(x % 3 == 1) q1.push(x);
            else if(x % 3 == 2) q2.push(x);
        }
        if((sum % 3 == 1 and q1.empty() and q2.sz < 2) or (sum % 3 == 2 and q2.empty() and q1.sz < 2))
            cout << -1;
        else
        {
            res = "";
            int s1 = -1, s2 = -1;
            if(sum % 3 == 1)
            {
                if(q1.empty())
                {
                    s1 = q2.top();
                    q2.pop();
                    s2 = q2.top();
                }
                else s1 = q1.top();
            }
            if(sum % 3 == 2)
            {
                if (q2.empty())
                {
                    s1 = q1.top();
                    q1.pop();
                    s2 = q1.top();
                }
                else s1 = q2.top();
            }
            while(pq.sz)
            {
                int tmp = pq.top();
                if(tmp != s1 and tmp != s2)
                    res += tmp + '0';
                else
                {
                    if (s1 == tmp) s1 = -1;
                    else if (s2 == tmp) s2 = -1;
                }
                pq.pop();
            }
            if(res.empty()) cout << -1;
            else
            {
                int idx = 0;
                while(res[idx] == '0')
                    ++idx;
                cout << res.substr(idx);
            }
        }
        cout << endl;
    }
    return 0;
}
