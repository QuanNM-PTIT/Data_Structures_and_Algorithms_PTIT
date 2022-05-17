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

inline binTree createNode(int val)
{
    binTree res = new Node;
    res -> val = val;
    res -> left = res -> right = NULL;
    return res;
}

inline void buildTree(binTree &T, int val)
{
    if(T == NULL)
        T = createNode(val);
    else
    {
        if(T -> val > val)
            buildTree(T -> left, val);
        else
            buildTree(T -> right, val);
    }
}

int MAX = -1;

inline void order(binTree T, int lv = 0)
{
    if(T)
    {
        if(T -> left == NULL and T -> right == NULL)
            MAX = max(MAX, lv);
        else
        {
            if(T -> left)
                order(T -> left, lv + 1);
            if(T -> right)
                order(T -> right, lv + 1);
        }
    }
}

int main()
{
    faster();
    int t = 1, n, x;
    cin >> t;
    while(t--)
    {
        cin >> n;
        binTree T = NULL;
        while(n--)
        {
            cin >> x;
            buildTree(T, x);
        }
        MAX = -1;
        order(T);
        cout << MAX;
        cout << endl;
    }
    return 0;
}
