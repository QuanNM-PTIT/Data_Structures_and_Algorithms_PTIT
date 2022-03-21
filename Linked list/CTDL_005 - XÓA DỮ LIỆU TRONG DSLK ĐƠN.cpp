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
    int n;
    Node* next;
};

typedef Node* node;

inline node createNode(int x)
{
    node res = new Node;
    res -> n = x;
    res -> next = NULL;
    return res;
}

inline void addBack(node &A, int x)
{
    if(A == NULL)
    {
        A = createNode(x);
        return;
    }
    node tmp = A;
    while(tmp -> next != NULL)
        tmp = tmp -> next;
    tmp -> next = createNode(x);
}

int main()
{
    faster();
    int t = 1, n, x;
    //cin >> t;
    while(t--)
    {
        cin >> n;
        node A = NULL;
        while(n--)
        {
            cin >> x;
            addBack(A, x);
        }
        cin >> x;
        while(A != NULL)
        {
            if(A -> n != x)
                cout << A -> n << ' ';
            A = A -> next;
        }
        delete A;
    }
    return 0;
}
