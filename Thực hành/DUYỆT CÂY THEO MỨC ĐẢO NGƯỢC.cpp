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

inline void BFS(binTree T)
{
    queue<binTree> q;
    stack<int> st;
    q.push(T);
    binTree top;
    while(q.sz)
    {
        top = q.front();
        q.pop();
        st.push(top -> val);
        if(top -> right)
            q.push(top -> right);
        if(top -> left)
            q.push(top -> left);
    }
    while(st.sz)
    {
        cout << st.top() << ' ';
        st.pop();
    }
}

int main()
{
    faster();
    int t = 1, n, child, par;
    char c;
    cin >> t;
    while(t--)
    {
        cin >> n;
        unordered_map<int, binTree> m;
        cin >> par >> child >> c;
        binTree T = createNode(par);
        if(c == 'L')
        {
            T -> left = createNode(child);
            m[child] = T -> left;
        }
        else
        {
            T -> right = createNode(child);
            m[child] = T -> right;
        }
        m[par] = T;
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
        BFS(T);
        cout << endl;
    }
    return 0;
}

