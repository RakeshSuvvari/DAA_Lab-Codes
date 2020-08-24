// Program to perform BFS of a graph from a vertex given by user
//Program also checks if another vertex(given by user) is reachable or not
#include "graph.h"
#include<algorithm>

void Graph::BFS3(Graph G,int s,int t) 
{ 
  bool *visited = new bool[V]; 
  for(int i = 0; i < V; i++) 
    visited[i] = false; 
    
  list<int> queue; 
  list<int> adjLists = adjList[V];
  visited[s] = true; 
  queue.push_back(s); 
  
  list<int>::iterator i; 	 
  s = queue.front(); 
  cout << s << " "; 
  queue.pop_front();  
  
  for (i = adjLists.begin(); i != adjLists.end(); ++i) 
   { 
    if (!visited[*i]) 
     { 
      visited[*i] = true; 
      queue.push_back(*i); 
     } 
   } 
  if(find(adjLists.begin(),adjLists.end(),t)!=adjLists.end())
      cout << "Reachable\n";
  else
      cout << "Not Reachable\n";
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
    cout << "BFS for given graph: "<<endl;
    g.BFS3(g,0,3); 
   
    return 0; 
}

