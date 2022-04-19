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

struct Node
{
    int val;
    Node *left, *right;
};

typedef Node* binTree;

inline binTree createNode(int x)
{
    binTree res = new Node;
    res -> val = x;
    res -> left = res -> right = NULL;
    return res;
}

inline void buildTree(binTree &root, int par, char c, int val)
{
    if(root == NULL)
        return;
    if(root -> val == par)
    {
        if(c == 'L')
            root -> left = createNode(val);
        else
            root -> right = createNode(val);
        return;
    }
    else
    {
        buildTree(root -> left, par, c, val);
        buildTree(root -> right, par, c, val);
    }
}

int Level[1005];
int a[35];

inline void order(binTree root, int lv = 0)
{
    if(root == NULL)
        return;
    ++Level[lv];
    order(root -> left, lv + 1);
    order(root -> right, lv + 1);
}

inline string check()
{
    for(int i = 0; i <= 30; ++i)
    {
        if(Level[i] == 0)
            return "Yes";
        if(Level[i] != a[i])
            return "No";
    }
    return "Yes";
}

int main()
{
    faster();
    int t, par, child, n;
    for(int i = 0; i <= 30; ++i)
        a[i] = 1 << i;
    char c;
    cin >> t;
    while(t--)
    {
        memset(Level, 0, sizeof(Level));
        cin >> n;
        binTree root;
        cin >> par >> child >> c;
        root = createNode(par);
        buildTree(root, par, c, child);
        --n;
        while(n--)
        {
            cin >> par >> child >> c;
            buildTree(root, par, c, child);
        }
        order(root);
        cout << check() << endl;
    }
    return 0;
}
