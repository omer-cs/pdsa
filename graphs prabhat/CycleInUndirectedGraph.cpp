#include <bits/stdc++.h>
using namespace std;

int findd(vector<int>&parent,int i)
{
    if(parent[i]==-1)
        return i;
    return findd(parent,parent[i]);
}

void unionn(vector<int>&parent,int x,int y)
{
    int xset=findd(parent,x);
    int yset=findd(parent,y);
    parent[xset]=yset;
}

int solve(int A, vector<vector<int> > &B) {   //B just contains two columns each row denoting an edge
    vector<int>parent(A+1,-1);     //A+1 cause nodes start from 1 assumed
    if(B.size()==1)
        return 0;
    for(int i=0;i<B.size();i++)
    {
        int u=B[i][0];
        int v=B[i][1];
        
        int set_u=findd(parent,u);
        int set_v=findd(parent,v);
        if(set_u==set_v)
            return 1;
        else
        {
            unionn(parent,set_u,set_v);
        }
    }
    return 0;
}

int main()
{

}