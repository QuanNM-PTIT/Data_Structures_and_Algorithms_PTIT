// Thuật toán Kruskal tìm cây khung nhỏ nhất của đồ thị
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

/*
    Cho đồ thị vô hướng G, có V đỉnh và E cạnh. Xây dựng cây khung nhỏ nhất của đồ thị.

    B1: Nhập danh sách kề và sort theo trọng số tăng dần.
    B2: Sử dụng DSU kiểm tra xem nếu nối 2 cạnh đó vào cây khung hiện tại có tạo thành 1 chu trình hay không?
        - Nếu tạo thành 1 chu trình, bỏ qua.
        - Nếu không tạo thành 1 chu trình, ta thêm cạnh đó vào cây khung.
*/

int v, e;
int Root[105], Size[105];
vector<pair<pair<int, int>, int>> vp;
int val;

// Tìm gốc
inline int findRoot(int x)
{
    if(x == Root[x])
        return x;
    return Root[x] = findRoot(Root[x]);
}

inline void Union(int x, int y, pair<pair<int, int>, int> p)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if(rootX != rootY)
    {
        val += p.se;
        if(Size[rootX] < Size[rootY])
            swap(rootX, rootY);
        Root[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

inline bool cmp(pair<pair<int, int>, int> a, pair<pair<int, int>, int> b)
{
    return a.se < b.se;
}

int main()
{
    faster();
    int x, y, z;
    cin >> v >> e;
    while(e--)
    {
        cin >> x >> y >> z;
        vp.pb({{x, y}, z});
    }
    sort(all(vp), cmp);
    val = 0;
    for(pair<pair<int, int>, int> &i : vp)
        Union(i.fi.fi, i.fi.se, i);
    cout << val;
    return 0;
}
