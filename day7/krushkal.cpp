#include <bits/stdc++.h> 
using namespace std; 

class Edge 
{ 
  public: 
  int src, dest, weight; 
}; 

class Graph 
{ 
  public:  
  int V, E; 
  Edge* edge; 
}; 
 
Graph* createGraph(int V, int E) 
{ 
 Graph* graph = new Graph; 
 graph->V = V; 
 graph->E = E; 

 graph->edge = new Edge[E]; 

 return graph; 
} 

class subset 
{ 
 public: 
  int parent; 
  int rank; 
}; 

int find(subset subsets[], int i) 
{ 
 if (subsets[i].parent != i) 
 subsets[i].parent = find(subsets, subsets[i].parent); 
 return subsets[i].parent; 
} 

void Union(subset subsets[], int x, int y) 
{ 
 int xroot = find(subsets, x); 
 int yroot = find(subsets, y); 
 if (subsets[xroot].rank < subsets[yroot].rank) 
  subsets[xroot].parent = yroot; 
 else if (subsets[xroot].rank > subsets[yroot].rank) 
  subsets[yroot].parent = xroot; 
 else
 { 
  subsets[yroot].parent = xroot; 
  subsets[xroot].rank++; 
 } 
} 

int myComp(const void* a, const void* b) 
{ 
 Edge* a1 = (Edge*)a; 
 Edge* b1 = (Edge*)b; 
 return a1->weight > b1->weight; 
}

 
void mst_krushkal(Graph* graph) 
{ 
 int V = graph->V; 
 Edge result[V];  
 
 int e = 0;  
 int i = 0; 
 
 qsort(graph->edge, graph->E, sizeof(graph->edge[0]), myComp); 
 subset *subsets = new subset[( V * sizeof(subset) )]; 

for (int v = 0; v < V; ++v) 
{ 
subsets[v].parent = v; 
subsets[v].rank = 0; 
} 
 
while (e < V - 1 && i < graph->E) 
{ 
 Edge next_edge = graph->edge[i++]; 
 int x = find(subsets, next_edge.src); 
 int y = find(subsets, next_edge.dest); 
 
 if (x != y) 
 { 
 result[e++] = next_edge; 
 Union(subsets, x, y); 
 }  
} 

 cout<<"The edges of the constructed MST using Krushkal's Algo are : \n"; 
 for (i = 0; i < e; ++i) 
  cout<< "From " << result[i].src << " to " << result[i].dest << ", Weight = "<< result[i].weight << endl; 
 return; 
} 

int main() 
{ 
 int V = 7; 
 int E = 11;  
 Graph* g = createGraph(V, E); 
	
	
 g->edge[0].src = 1; 
 g->edge[0].dest = 2; 
 g->edge[0].weight = 7; 
 	
 g->edge[1].src = 1; 
 g->edge[1].dest = 4; 
 g->edge[1].weight = 5; 
	
 g->edge[2].src = 2; 
 g->edge[2].dest = 3; 
 g->edge[2].weight = 8; 
	
 g->edge[3].src = 2; 
 g->edge[3].dest = 4; 
 g->edge[3].weight = 9; 

 g->edge[4].src = 2; 
 g->edge[4].dest = 5; 
 g->edge[4].weight = 7; 
	
 g->edge[5].src = 3; 
 g->edge[5].dest = 5; 
 g->edge[5].weight = 5; 

 g->edge[6].src = 4; 
 g->edge[6].dest = 5; 
 g->edge[6].weight = 15; 
	
 g->edge[7].src = 4; 
 g->edge[7].dest = 6; 
 g->edge[7].weight = 6; 
	
 g->edge[8].src = 5; 
 g->edge[8].dest = 6; 
 g->edge[8].weight = 8;

 g->edge[9].src = 5; 
 g->edge[9].dest = 7; 
 g->edge[9].weight = 9;
	
 g->edge[10].src = 6; 
 g->edge[10].dest = 7; 
 g->edge[10].weight = 11;
	
 mst_krushkal(g); 

return 0; 
} 


