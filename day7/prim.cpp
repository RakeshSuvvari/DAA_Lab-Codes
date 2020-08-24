#include <bits/stdc++.h> 
using namespace std; 

#define V 7 

int minKey(int key[], bool mstSet[]) 
{ 
	 
 int min = INT_MAX, min_index; 
  for (int v = 0; v < V; v++) 
   if (mstSet[v] == false && key[v] < min) 
    min = key[v], min_index = v; 

 return min_index; 
} 
 
void mst_prim(int graph[V][V]) 
{  
 int parent[V]; 
 int key[V];  
 bool mstSet[V]; 
 for (int i = 0; i < V; i++) 
  key[i] = INT_MAX, mstSet[i] = false; 

 key[0] = 0; 
 parent[0] = -1;  

for (int count = 0; count < V - 1; count++) 
{  
 int u = minKey(key, mstSet); 
 mstSet[u] = true; 
 for (int v = 0; v < V; v++)  
  if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v]) 
   parent[v] = u, key[v] = graph[u][v]; 
} 
	
 cout << "The edges of the constructed MST from Prim's Algo are :" << endl;
 for (int i = 1; i < V; i++) 
  cout << "From " << parent[i] << " to " << i << " ,Weight = " << graph[i][parent[i]] << endl; 
} 
 
int main() 
{ 
int graph[V][V] = { 	{ 0, 7, 0, 5, 0, 0, 0 }, 
			{ 7, 0, 8, 9, 7, 0, 0 },
			{ 0, 8, 0, 0, 5, 0, 0 },
			{ 5, 9, 0, 0, 15, 6, 0 },
			{ 0, 7, 5, 15, 0, 8, 9 },
			{ 0, 0, 0, 6, 8, 0, 11 },
			{ 0, 0, 0, 0, 9, 11, 0 }, }; 

	 
mst_prim(graph); 

return 0; 
} 


