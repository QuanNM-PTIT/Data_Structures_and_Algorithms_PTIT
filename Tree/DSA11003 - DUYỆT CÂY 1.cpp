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

int pos = 0;

inline void print(int inorder[], int preorder[], int l, int r, unordered_map<int, int> &m)
{
    if(l <= r)
    {
        int idx = m[preorder[pos++]];
        print(inorder, preorder, l, idx - 1, m);
        print(inorder, preorder, idx + 1, r, m);
        cout << inorder[idx] << " ";
    }
}

int main()
{
    faster();
    int t = 1, n;
    cin >> t;
    while(t--)
    {
        cin >> n;
        int inorder[n], preorder[n];
        for(int &i : inorder)
            cin >> i;
        for(int &i : preorder)
            cin >> i;
        unordered_map<int, int> m;
        for (int i = 0; i < n; ++i)
            m[inorder[i]] = i;
        pos = 0;
        print(inorder, preorder, 0, n - 1, m);
        cout << endl;
    }
    return 0;
}