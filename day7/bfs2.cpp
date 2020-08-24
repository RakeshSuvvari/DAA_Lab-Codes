// Program to perform BFS of a graph from a vertex given by user
#include "graph.h"

void Graph::BFS2(Graph G,int s) 
{ 
  bool *visited = new bool[V]; 
  for(int i = 0; i < V; i++) 
   visited[i] = false; 
 list<int> queue; 
 visited[s] = true; 
 queue.push_back(s); 
 list<int>::iterator i; 
 while(!queue.empty()) 
  { 	 
   s = queue.front(); 
   cout << s << " "; 
   queue.pop_front();  
   for (i = adjList[s].begin(); i != adjList[s].end(); ++i) 
   { 
    if (!visited[*i]) 
    { 
     visited[*i] = true; 
     queue.push_back(*i); 
    } 
   } 
   } 
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
  cout << "BFS for given graph:" <<endl;
  g.BFS2(g,0); 
   
    return 0; 
}
