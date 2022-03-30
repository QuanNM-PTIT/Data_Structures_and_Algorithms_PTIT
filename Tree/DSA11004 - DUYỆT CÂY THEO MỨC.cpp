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

inline void buildTree(binTree &A, char c, int par, int child)
{
    if(A != NULL)
    {
        if(A -> val == par)
        {
            if(c == 'L')
                A -> left = createNode(child);
            else
                A -> right = createNode(child);
        }
        buildTree(A -> left, c, par, child);
        buildTree(A -> right, c, par, child);
    }
}

inline void levelOrder(binTree root)
{
    queue<binTree> q;
    binTree top;
    q.push(root);
    while(q.sz)
    {
        top = q.front();
        q.pop();
        cout << top -> val << ' ';
        if(top -> left != NULL)
            q.push(top -> left);
        if(top -> right != NULL)
            q.push(top -> right);
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
        binTree root = NULL;
        int par, child;
        char c;
        cin >> par >> child >> c;
        root = createNode(par);
        buildTree(root, c, par, child);
        --n;
        while(n--)
        {
            cin >> par >> child >> c;
            buildTree(root, c, par, child);
        }
        levelOrder(root);
        cout << endl;
    }
    return 0;
}
