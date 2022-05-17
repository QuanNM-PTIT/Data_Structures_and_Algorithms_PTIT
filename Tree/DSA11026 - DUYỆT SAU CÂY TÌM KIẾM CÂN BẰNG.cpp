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

int a[1000005];

struct Node
{
    int val;
    Node *left, *right;
};

typedef Node* binTree;

inline binTree createNode(int val)
{
    binTree res = new Node;
    res -> val = val;
    res -> left = res -> right = NULL;
    return res;
}

inline binTree buildTree(int l, int r)
{
    if(l > r)
        return NULL;
    int mid = (l + r) >> 1;
    binTree res = createNode(a[mid]);
    res -> left = buildTree(l, mid - 1);
    res -> right = buildTree(mid + 1, r);
    return res;
}

inline void order(binTree T)
{
    if(T)
    {
        if(T -> left)
            order(T -> left);
        if(T -> right)
            order(T -> right);
        cout << T -> val << ' ';
    }
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        sort(a, a + n);
        binTree T = buildTree(0, n - 1);
        order(T);
        cout << endl;
    }
    return 0;
}
