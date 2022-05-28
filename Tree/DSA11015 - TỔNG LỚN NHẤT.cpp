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

inline void buildTree(binTree &T, int par, int child, char c)
{
    if(T)
    {
        if(T -> val == par)
        {
            if(c == 'L')
                T -> left = createNode(child);
            else
                T -> right = createNode(child);
            return;
        }
        else
        {
            buildTree(T -> left, par, child, c);
            buildTree(T -> right, par, child, c);
        }
    }
}

int MAX;

inline int findMax(binTree T)
{
    if(T == NULL)
        return 0;
    int L = findMax(T -> left), R = findMax(T -> right);
    if(T -> left == NULL and T -> right == NULL)
        return T -> val;
    if(T -> left == NULL)
        return R + T -> val;
    if(T -> right == NULL)
        return L + T -> val;
    MAX = max(MAX, L + R + T -> val);
    return max(L, R) + T -> val;
}

int main()
{
    faster();
    int t = 1, n, par, child;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> n;
        binTree T = NULL;
        cin >> par >> child >> c;
        T = createNode(par);
        buildTree(T, par, child, c);
        while(--n)
        {
            cin >> par >> child >> c;
            buildTree(T, par, child, c);
        }
        MAX = -1e9;
        findMax(T);
        cout << MAX << endl;
    }
    return 0;
}