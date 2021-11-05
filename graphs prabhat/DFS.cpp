#include <bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    vector<vector<int>>adj;
    void DFS_util(int v,vector<bool>&visited);
public:
    Graph(int V);
    void addEdge(int v,int w);
    void DFS(int s);
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



void Graph::DFS_util(int s,vector<bool>&visited)
{
    visited[s]=true;
    cout<<s<<" ";
    for(int i=0;i<adj[s].size();i++)
    {
        if(!visited[adj[s][i]])
            DFS_util(adj[s][i],visited);
    }
}

void Graph::DFS(int s)
{
    vector<bool>visited(V,false);
    DFS_util(s,visited);
}

int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 0); 
    g.addEdge(2, 3); 
    g.addEdge(3, 3); 
    cout << "Following is Depth First Traversal (starting from vertex 2) \n"; 
    g.DFS(2); 
    return 0; 
}