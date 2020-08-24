// Program to perform DFS of a graph from a vertex given by user
#include "graph.h"
void Graph::DFS2(Graph G,int s)
{

 visited[s] = true;
 list<int> adjLists = adjList[s];
 cout << s << " ";
 
 list<int>::iterator i;
 for(i = adjLists.begin(); i != adjLists.end(); ++i)
  if(!visited[*i])
   DFS2(G,*i);
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
 g.DFS2(g,1);
return 0;
}
