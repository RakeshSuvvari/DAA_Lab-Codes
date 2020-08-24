// Program to perform DFS of a graph from a random vertex
#include "graph.h"

void Graph::DFS_util(int v, bool visited[]) 
{  	
  visited[v] = true; 
  cout << v << " ";  
  list<int>::iterator i; 
  for(i = adjList[v].begin(); i != adjList[v].end(); ++i) 
  if(!visited[*i]) 
  DFS_util(*i, visited); 
} 
    
void Graph::DFS1(Graph G) 
{ 
 bool *visited = new bool[V]; 
 for (int i = 0; i < V; i++) 
  visited[i] = false; 
 
 for (int i = 0; i < V; i++) 
  if (visited[i] == false) 
   DFS_util(i, visited); 
} 
   
int main() 
{ 	
 Graph g(7); 
 g.addEdge(0, 1); 
 g.addEdge(0, 2); 
 g.addEdge(1, 3); 
 g.addEdge(1, 4); 
 g.addEdge(3, 4); 
 g.addEdge(4, 6); 
 g.addEdge(2, 5); 
 g.addEdge(5, 6); 
 cout << "DFS for the given graph:" << endl; 
 g.DFS1(g); 
 return 0; 
}
