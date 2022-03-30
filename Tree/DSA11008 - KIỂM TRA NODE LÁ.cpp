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

inline int levelOrder(binTree root)
{
    int MAX = -1;
    queue<pair<binTree, int>> q;
    pair<binTree, int> top;
    q.push({root, 0});
    while(q.sz)
    {
        top = q.front();
        q.pop();
        if(top.fi -> left == NULL)
        {
            if(MAX == -1)
                MAX = top.se;
            else if(top.se != MAX)
                return 0;
        }
        else
            q.push({top.fi -> left, top.se + 1});
        if(top.fi -> right == NULL)
        {
            if(MAX == -1)
                MAX = top.se;
            else if(top.se != MAX)
                return 0;
        }
        else
            q.push({top.fi -> right, top.se + 1});
    }
    return 1;
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
        cout << levelOrder(root) << endl;
    }
    return 0;
}
