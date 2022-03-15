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

class Matrix
{
private:
    int a[2][3];
    int cnt;
    
public:
    friend istream &operator >> (istream &is, Matrix &A)
    {
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                is >> A.a[i][j];
        return is;
    }
    
    bool operator == (Matrix &A)
    {
        for(int i = 0; i < 2; ++i)
            for(int j = 0; j < 3; ++j)
                if(this -> a[i][j] != A.a[i][j])
                    return 0;
        return 1;
    }
    
    void rotateRight()
    {
        int x, y, z, t;
        x = this -> a[0][1];
        y = this -> a[0][2];
        z = this -> a[1][1];
        t = this -> a[1][2];
        this -> a[0][1] = z;
        this -> a[0][2] = x;
        this -> a[1][1] = t;
        this -> a[1][2] = y;
    }
    
    void rotateLeft()
    {
        int x, y, z, t;
        x = this -> a[0][0];
        y = this -> a[0][1];
        z = this -> a[1][0];
        t = this -> a[1][1];
        this -> a[0][0] = z;
        this -> a[0][1] = x;
        this -> a[1][0] = t;
        this -> a[1][1] = y;
    }
    
    int getCnt()
    {
        return this -> cnt;
    }
    
    void updateCnt(int x)
    {
        this -> cnt = x;
    }
};

Matrix S, E, u, tmp;

inline void BFS()
{
    queue<Matrix> q;
    q.push(S);
    S.updateCnt(0);
    vector<Matrix> v;
    v.pb(S);
    while(q.sz)
    {
        u = q.front();
        q.pop();
        tmp = u;
        tmp.rotateLeft();
        tmp.updateCnt(u.getCnt() + 1);
        if(tmp == E)
        {
            cout << tmp.getCnt() << endl;
            return;
        }
        q.push(tmp);
        tmp = u;
        tmp.rotateRight();
        tmp.updateCnt(u.getCnt() + 1);
        if(tmp == E)
        {
            cout << tmp.getCnt() << endl;
            return;
        }
        q.push(tmp);
    }
}

int main()
{
    faster();
    int t = 1;
    cin >> t;
    while(t--)
    {
        cin >> S >> E;
        if(S == E)
        {
            cout << 0 << endl;
            continue;
        }
        BFS();
    }
    return 0;
}