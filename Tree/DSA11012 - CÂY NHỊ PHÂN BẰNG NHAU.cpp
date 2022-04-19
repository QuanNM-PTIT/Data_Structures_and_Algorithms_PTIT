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

inline void order(binTree root1, binTree root2)
{
    if(!check or root1 == NULL or root2 == NULL)
        return;
    if(root1 -> val != root2 -> val)
    {
        check = 0;
        return;
    }
    if((root1 -> left == NULL and root2 -> left != NULL) or (root1 -> right == NULL and root2 -> right != NULL))
    {
        check = 0;
        return;
    }
    order(root1 -> left, root2 -> left);
    order(root1 -> right, root2 -> right);
}

int main()
{
    faster();
    int t, n, par, child, ori;
    char c;
    string s;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ori = n;
        binTree root1, root2;
        cin >> par >> child >> c;
        root1 = createNode(par);
        buildTree(root1, par, c, child);
        --n;
        while(n--)
        {
            cin >> par >> child >> c;
            buildTree(root1, par, c, child);
        }
        check = 1;
        cin >> n;
        if(n != ori)
        {
            cin.ignore();
            getline(cin, s);
            cout << 0 << endl;
            continue;
        }
        cin >> par >> child >> c;
        root2 = createNode(par);
        buildTree(root2, par, c, child);
        --n;
        while(n--)
        {
            cin >> par >> child >> c;
            buildTree(root2, par, c, child);
        }
        order(root1, root2);
        cout << check << endl;
    }
    return 0;
}
