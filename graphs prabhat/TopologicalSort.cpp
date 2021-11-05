#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>adj;
    void DFS_util(int v,vector<bool>&visited,vector<int>&ans); //need dfs to traverse till the farthest edge
public:
    Graph(int V);
    void addEdge(int v,int w);
    vector<int>topologicalSort();
};

Graph::Graph(int V)   //constructor
{
    this->V=V;
    adj=vector<vector<int>>(V);
    
}
void Graph::addEdge(int v ,int w)
{
    adj[v].push_back(w);
}



void Graph::DFS_util(int s,vector<bool>&visited,vector<int>&ans)
{
    // cout<<"vertex : "<<s<<endl;
    visited[s]=true;
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
            DFS_util(adj[s][i],visited,ans);
    }
    ans.push_back(s);  //important step to push the source after u traversed the whole path
}

vector<int> Graph::topologicalSort()
{
    vector<bool>visited(V,false);
    vector<int>ans;
    for(int i=0;i<V;i++)
    {
        if(!visited[i])
            DFS_util(i,visited,ans);
    }
    reverse(ans.begin(),ans.end());
    return ans;
}

int main()
{
        //     1
        //   / | \
        //  0  2  5
        //  \ /  /
        //   3  /
        //   | /
        //   4
    Graph g(4); 
    g.addEdge(0, 2); 
    g.addEdge(2, 1); 
    g.addEdge(4, 3); 
    vector<int>result=g.topologicalSort();
    for(int i=0;i<result.size();i++)
        cout<<result[i]<<" ";
}