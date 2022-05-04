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

int n;
int Root[105];
map<int, pair<double, double>> m;

struct Element
{
    int a, b;
    double dist;
};

int root(int i)
{
    if (Root[i] == -1) return i;
    else
    {
        int x = root(Root[i]);
        Root[i] = x;
        return x;
    }
}

bool cmp3(Element a, Element b)
{
    return a.dist < b.dist;
}

double calc(int i, int j)
{
    double a1 = m[i].fi, b1 = m[i].se, a2 = m[j].fi, b2 = m[j].se;
    return sqrt((a1 - a2) * (a1 - a2) + (b1 - b2) * (b1 - b2));
}

int main()
{
    faster();
    int t;
    cin >> t;
    while(t--)
    {
        Element a[10005];
        cin >> n;
        pair<double, double> A;
        double MAX = 0;
        int idx = 0;
        for(int i = 1; i <= n; ++i)
        {
            cin >> A.fi >> A.se;
            m[i] = A;
        }
        Element P;
        for(int i = 1; i <= n; ++i)
        {
            for(int j = i + 1; j <= n; ++j)
            {
                P = {i, j};
                P.dist = calc(i, j);
                a[idx] = P;
                ++idx;
            }
        }
        sort(a, a + idx, cmp3);
        for(int i = 0; i <= n; ++i)
            Root[i] = -1;
        int p, q;
        for(int i = 0; i < idx; ++i)
        {
            P = a[i];
            p = root(P.a);
            q = root(P.b);
            if(p != q)
            {
                Root[p] = q;
                MAX += P.dist;
            }
        }
        cout << setprecision(6) << fixed << MAX << endl;
        m.clear();
    }
    return 0;
}
