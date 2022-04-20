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

bool check;
ll sum;

bool isLeaf(binTree root)
{
    return root -> left == root -> right and root -> left == NULL;
}

inline void calc(binTree root)
{
    if(root == NULL)
        return;
    if(root -> right != NULL and isLeaf(root -> right))
        sum += root -> right -> val;
    if(root -> right != NULL and !isLeaf(root -> right))
        calc(root -> right);
    if(root -> left != NULL and !isLeaf(root -> left))
        calc(root -> left);
}

int main()
{
    faster();
    int t, n, par, child, ori;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> n;
        ori = n;
        binTree root;
        unordered_map<int, binTree> m;
        cin >> par >> child >> c;
        root = createNode(par);
        if(c == 'L')
        {
            root -> left = createNode(child);
            m[child] = root -> left;
        }
        else
        {
            root -> right = createNode(child);
            m[child] = root -> right;
        }
        m[par] = root;
        --n;
        while(n--)
        {
            cin >> par >> child >> c;
            if(c == 'L')
            {
                m[par] -> left = createNode(child);
                m[child] = m[par] -> left;
            }
            else
            {
                m[par] -> right = createNode(child);
                m[child] = m[par] -> right;
            }
        }
        sum = 0;
        calc(root);
        cout << sum << endl;
        free(root);
    }
    return 0;
}