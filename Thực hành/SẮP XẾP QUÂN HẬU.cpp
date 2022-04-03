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

int ans, n = 8;
bitset<16> x, y;
bitset<9> f;
vector<vi> a(9, vi (9));

void Try(int i, int sum = 0)
{
    if(i > n)
    {
        ans = max(ans, sum);
        return;
    }
    for(int j = 1; j <= n; ++j)
        if(!f[j] and !x[j + i - 1] and !y[j - i + n])
        {
            f[j] = 1;
            x[j + i - 1] = 1;
            y[j - i + n] = 1;
            Try(i + 1, sum + a[i][j]);
            f[j] = 0;
            x[j + i - 1] = 0;
            y[j - i + n] = 0;
        }
}

int main()
{
    faster();
    int t = 1, cnt = 1;
    cin >> t;
    while(t--)
    {
        ans = 0;
        for(int i = 1; i <= 8; i++)
            for(int j = 1; j <= 8; j++)
                cin >> a[i][j];
        Try(1);
        cout << "Test " << cnt++ << ": " << ans << endl;
    }
    return 0;
}
