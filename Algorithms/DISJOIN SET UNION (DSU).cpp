// Cấu trúc dữ liệu Disjoin Set Union
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

int Root[1005]; // Root[i]: Gốc của đỉnh i
int Size[1005]; // Size[i]: Số con của gốc i

// Tìm gốc
int findRoot(int x)
{
    if(x == Root[x])
        return x;
    return Root[x] = findRoot(Root[x]);
}

// Hợp 2 tập hợp
void Union(int x, int y)
{
    int rootX = findRoot(x), rootY = findRoot(y);
    if(rootX != rootY)
    {
        if(Size[rootX] < Size[rootY])
            swap(rootX, rootY);
        Root[rootY] = rootX;
        Size[rootX] += Size[rootY];
    }
}

int main()
{
    faster();
    int n;
    // Ban đầu khởi tạo gốc của đỉnh i là chính nó
    for(int i = 1; i <= n; ++i)
        Root[i] = i;
    return 0;
}
