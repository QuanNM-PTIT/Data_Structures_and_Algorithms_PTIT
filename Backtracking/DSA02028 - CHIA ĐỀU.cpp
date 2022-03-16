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

int n, k;
int a[15], check, res = 0;
vi sum(15);

void Try(int i, int cnt = 0)
{
    if(cnt == k)
    {
        res += i == n;
        return;
    }
    for(int j = i + 1; j <= n; ++j) if(sum[j] - sum[i] == check) Try(j, cnt + 1);
}

int main()
{
    faster();
    int t = 1;
    //cin >> t;
    while(t--)
    {
        cin >> n >> k;
        for(int i = 1; i <= n; ++i)
        {
            cin >> check;
            sum[i] = sum[i - 1] + check;
        }
        if(sum[n] % k) return cout << 0, 0;
        check = sum[n] / k;
        Try(0);
        cout << res;
    }
    return 0;
}
