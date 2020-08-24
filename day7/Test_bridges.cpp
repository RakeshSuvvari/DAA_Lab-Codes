#include "graph.h"
#define NIL -1 


void Graph::bridge(int u, bool visited[], int disc[], int low[], int parent[]) 
{ 
 static int time = 0;  
 visited[u] = true; 
 disc[u] = low[u] = ++time;  
 list<int>::iterator i; 
 
 for (i = adjList[u].begin(); i != adjList[u].end(); ++i) 
 { 
  int v = *i;   
  if (!visited[v]) 
  { 
   parent[v] = u; 
   bridge(v, visited, disc, low, parent); 
   low[u] = min(low[u], low[v]); 
   if (low[v] > disc[u]) 
     cout << u <<" " << v << endl; 
  } 
 else if (v != parent[u]) 
   low[u] = min(low[u], disc[v]); 
 } 
 
} 
 
void Graph::test_bridges(Graph G) 
{ 
  bool *visited = new bool[V]; 
  int *disc = new int[V]; 
  int *low = new int[V]; 
  int *parent = new int[V]; 
  for (int i = 0; i < V; i++) 
  { 
   parent[i] = NIL; 
   visited[i] = false; 
  }  
  for (int i = 0; i < V; i++) 
   if (visited[i] == false) 
    bridge(i, visited, disc, low, parent); 
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
	cout << "\nBridges in given graph: \n";
	g.test_bridges(g); 

	return 0; 
} 

