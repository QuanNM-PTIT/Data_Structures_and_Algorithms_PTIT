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
    char c;
    Node *left, *right;
};

typedef Node* binTree;

inline binTree createNode(char c)
{
    binTree res = new Node;
    res -> c = c;
    res -> left = res -> right = NULL;
    return res;
}

inline void order(binTree a)
{
    if(a != NULL)
    {
        order(a -> left);
        cout << a -> c;
        order(a -> right);
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    string s;
    while(t--)
    {
        cin >> s;
        stack<binTree> st;
        for(char &i : s)
        {
            if(i == '+' or i == '-' or i == '*' or i == '/')
            {
                binTree tmp = createNode(i);
                tmp -> right = st.top();
                st.pop();
                tmp -> left = st.top();
                st.pop();
                st.push(tmp);
            }
            else st.push(createNode(i));
        }
        order(st.top());
        cout << endl;
    }
    return 0;
}