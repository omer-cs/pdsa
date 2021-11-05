#include <bits/stdc++.h>
using namespace std;


class Graph
{
    int V;                          //number of vertices
    vector<vector<int>>adj;         //adj list
public:
    Graph(int V);
    void addEdge(int v,int w);
    void BFS(int s);
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

void Graph::BFS(int s)
{
    vector<bool>visited(V,false);
    visited[s]=true;
    queue<int>q;
    q.push(s);
    while(!q.empty())
    {
        s=q.front();
        q.pop();
        cout<<s<<" ";
        for(int i=0;i<adj[s].size();i++)
        {
            if(!visited[adj[s][i]])
            {
                visited[adj[s][i]]=true;
                q.push(adj[s][i]);
            }
        }

    }
}

int main()
{
    Graph g(4); 
    g.addEdge(0, 1); 
    g.addEdge(0, 2); 
    g.addEdge(1, 2); 
    g.addEdge(2, 3); 
    g.addEdge(2, 0); 
    g.addEdge(3, 3); 
    cout << "Following is Breadth First Traversal (starting from vertex 2) \n"; 
    g.BFS(2); 
    return 0; 
}