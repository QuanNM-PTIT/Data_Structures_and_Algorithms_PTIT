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

binTree createNode(int x)
{
    binTree res = new Node;
    res -> val = x;
    res -> left = res -> right = NULL;
    return res;
}

void buildTree(binTree root, int par, int child, char x)
{
    if(root != NULL)
    {
        if(root -> val == par)
        {
            if(x == 'L')
                root -> left = createNode(child);
            else
                root -> right = createNode(child);
            return;
        }
        buildTree(root -> left, par, child, x);
        buildTree(root -> right, par, child, x);
    }
}

void spiralOrder(binTree root)
{
    stack<binTree> st1, st2;
    st1.push(root);
    binTree top;
    while(st1.sz or st2.sz)
    {
        while(st1.sz)
        {
            top = st1.top();
            st1.pop();
            cout << top -> val << ' ';
            if(top -> right != NULL)
                st2.push(top -> right);
            if(top -> left != NULL)
                st2.push(top -> left);
        }
        while(st2.sz)
        {
            top = st2.top();
            st2.pop();
            cout << top -> val << ' ';
            if(top -> left != NULL)
                st1.push(top -> left);
            if(top -> right != NULL)
                st1.push(top -> right);
        }
    }
}

int main()
{
    faster();
    int t, n;
    cin >> t;
    int child, par;
    char x;
    while(t--)
    {
        cin >> n;
        binTree root = NULL;
        cin >> par >> child >> x;
        root = createNode(par);
        buildTree(root, par, child, x);
        --n;
        while(n--)
        {
            cin >> par >> child >> x;
            buildTree(root, par, child, x);
        }
        spiralOrder(root);
        cout << endl;
    }
    return 0;
}
