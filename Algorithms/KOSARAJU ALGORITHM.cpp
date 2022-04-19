// Thuật toán Kosaraju tìm số thành phần liên thông mạnh
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

// B1: DFS trên G => Lưu vào stack
// B2: Lấy các đỉnh trong stack lần lượt ra và DFS trên TG (Đảo chiều của G)
/* Đồ thị G có hướng:
     9
     1 2
     2 3
     3 4
     4 1
     3 5
     5 6
     6 7
     7 8
     8 6
*/

vector<int> a[100]; // Danh sách cạnh của G
vector<int> b[100]; // Danh sách cạnh của TG
stack<int> st;
bitset<100> bs;

void DFS(int x)
{
    bs[x] = 1;
    for(int i : a[x])
        if(!bs[i])
            DFS(i);
    st.push(x);
}

void DFS2(int x)
{
    cout << x << ' ';
    bs[x] = 1;
    for(int i : b[x])
        if(!bs[i])
            DFS2(i);
}

int main()
{
    faster();
    int n, x, y;
    cin >> n;
    while(n--)
    {
        cin >> x >> y;
        a[x].pb(y);
        b[y].pb(x);
    }
    DFS(1);
    bs.reset();
    // Tìm số thành phần liên thông mạnh
    while(st.sz)
    {
        if(!bs[st.top()])
        {
            DFS2(st.top());
            cout << endl;
        }
        st.pop();
    }
    return 0;
}
