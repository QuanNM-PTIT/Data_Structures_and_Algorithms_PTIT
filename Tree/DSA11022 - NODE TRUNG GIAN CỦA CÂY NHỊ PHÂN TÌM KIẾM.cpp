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

int cnt = 0;

inline void order(binTree T)
{
    if(T)
    {
        if(T -> left == NULL and T -> right == NULL)
            return;
        else
        {
            ++cnt;
            if(T -> left)
                order(T -> left);
            if(T -> right)
                order(T -> right);
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
        cnt = 0;
        order(T);
        cout << cnt;
        cout << endl;
    }
    return 0;
}
