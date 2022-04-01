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

binTree createNode(int x)
{
    binTree res = new Node;
    res -> val = x;
    res -> left = res -> right = NULL;
    return res;
}

binTree buildTree(int n, int *inorder, int *levelOrder, int st, int e)
{
    if(n > 0)
    {
        binTree root = createNode(levelOrder[0]);
        int idx = -1;
        unordered_map<int, int> m;
        for(int i = st; i <= e; ++i)
        {
            if(inorder[i] == levelOrder[0])
            {
                idx = i;
                break;
            }
            ++m[inorder[i]];
        }
        int L[m.sz], R[e - st - m.sz], l, r;
        l = r = 0;
        for(int i = 1; i < n; ++i)
        {
            if(m[levelOrder[i]])
                L[l++] = levelOrder[i];
            else
                R[r++] = levelOrder[i];
        }
        root -> left = buildTree(idx - st, inorder, L, st, idx - 1);
        root -> right = buildTree(e - idx, inorder, R, idx + 1, e);
        return root;
    }
    return NULL;
}

void postOrder(binTree root)
{
    if(root -> left != NULL)
        postOrder(root -> left);
    if(root -> right != NULL)
        postOrder(root -> right);
    cout << root -> val << ' ';
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int inorder[n], levelOrder[n];
        for(int &i : inorder)
            cin >> i;
        for(int &i : levelOrder)
            cin >> i;
        binTree root = buildTree(n, inorder, levelOrder, 0, n - 1);
        postOrder(root);
        cout << endl;
    }
    return 0;
}
