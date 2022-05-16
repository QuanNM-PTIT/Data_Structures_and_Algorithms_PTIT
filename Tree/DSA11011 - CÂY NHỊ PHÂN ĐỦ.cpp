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

binTree createNode(int val)
{
    binTree res = new Node;
    res -> val = val;
    res -> left = res -> right = NULL;
    return res;
}

bool check;

void order(binTree A)
{
    if(!check)
        return;
    if(A)
    {
        if((A -> left == NULL and A -> right) or (A -> left and A -> right == NULL))
        {
            check = 0;
            return;
        }
        if(A -> left)
            order(A -> left);
        if(A -> right)
            order(A -> right);
    }
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
        unordered_map<int, binTree> m;
        cin >> par >> child >> c;
        binTree T = createNode(par);
        m[par] = T;
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
        check = 1;
        order(T);
        cout << check << endl;
    }
    return 0;
}
