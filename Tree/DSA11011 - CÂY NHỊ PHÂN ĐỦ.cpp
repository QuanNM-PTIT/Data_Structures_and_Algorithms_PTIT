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

inline binTree createNode(int val)
{
    binTree res = new Node;
    res -> val = val;
    res -> left = res -> right = NULL;
    return res;
}

inline void buildTree(binTree &root, int par, char c, int child)
{
    if(root == NULL)
        return;
    if(par == root -> val)
    {
        if(c == 'L')
            root -> left = createNode(child);
        else
            root -> right = createNode(child);
    }
    buildTree(root -> left, par, c, child);
    buildTree(root -> right, par, c, child);
}

bool check;

inline void order(binTree root)
{
    if(!check or root == NULL)
        return;
    if((root -> left == NULL and root -> right != NULL) or (root -> right == NULL and root -> left != NULL))
    {
        check = 0;
        return;
    }
    order(root -> left);
    order(root -> right);
}

int main()
{
    faster();
    int t, n, par, child;
    char c;
    cin >> t;
    while(t--)
    {
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
        check = 1;
        order(root);
        cout << check << endl;
    }
    return 0;
}
