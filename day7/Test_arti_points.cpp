#include "graph.h" 
#define NIL -1 


void Graph::AP(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]) 
{  
 static int time = 0;  
 int children = 0; 
 visited[u] = true; 
 disc[u] = low[u] = ++time;  
 list<int>::iterator i; 
 for (i = adjList[u].begin(); i != adjList[u].end(); ++i) 
 { 
  int v = *i;  
  if (!visited[v]) 
  { 
   children++; 
   parent[v] = u; 
  AP(v, visited, disc, low, parent, ap); 
  low[u] = min(low[u], low[v]);  
  if (parent[u] == NIL && children > 1) 
   ap[u] = true; 
  if (parent[u] != NIL && low[v] >= disc[u]) 
   ap[u] = true; 
  } 
   
  else if (v != parent[u]) 
   low[u] = min(low[u], disc[v]); 
 } 
} 
 
void Graph::test_articulationpoints(Graph G) 
{  
 bool *visited = new bool[V]; 
 int *disc = new int[V]; 
 int *low = new int[V]; 
 int *parent = new int[V]; 
 bool *ap = new bool[V];   
 for (int i = 0; i < V; i++) 
 { 
  parent[i] = NIL; 
  visited[i] = false; 
  ap[i] = false; 
 }  

 for (int i = 0; i < V; i++) 
  if (visited[i] == false) 
   AP(i, visited, disc, low, parent, ap); 
 
 for (int i = 0; i < V; i++) 
  if (ap[i] == true) 
   cout << i << " "; 
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
	cout << "\nArticulation points in given graph: \n";
	g.test_articulationpoints(g); 

	return 0; 
} 

