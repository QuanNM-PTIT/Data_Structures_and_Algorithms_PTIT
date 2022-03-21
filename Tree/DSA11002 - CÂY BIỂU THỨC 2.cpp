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

int n;
string a[150];

struct Node
{
    string s;
    Node *left, *right;
};

typedef Node* binTree;

inline binTree createNode(string s)
{
    binTree res = new Node;
    res -> s = s;
    res -> left = res -> right = NULL;
    return res;
}

inline binTree buildTree(binTree root, int i)
{
    if(i < n)
    {
        root = createNode(a[i]);
        root -> left = buildTree(root -> left , (i << 1) + 1);
        root -> right = buildTree(root -> right, (i << 1) + 2);
    }
    return root;
}

inline ll calc(binTree root)
{
    if(root -> s != "+" and root -> s != "-" and root -> s != "*" and root -> s != "/")
        return stoll(root -> s);
    if(root -> s == "+")
        return calc(root -> left) + calc(root -> right);
    else if(root -> s == "-")
        return calc(root -> left) - calc(root -> right);
    else if(root -> s == "*")
        return calc(root -> left) * calc(root -> right);
    else
        return calc(root -> left) / calc(root -> right);
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> n;
        int i = 0;
        for(int i = 0; i < n; ++i)
            cin >> a[i];
        binTree A = NULL;
        A = buildTree(A, 0);
        cout << calc(A) << endl;
        delete A;
    }
    return 0;
}