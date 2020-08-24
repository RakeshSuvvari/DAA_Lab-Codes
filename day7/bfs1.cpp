// Program to perform BFS of a graph from a randon vertex
#include "graph.h"

void Graph::BFS1(Graph G)
{
 queue <int> myQueue;
 bool * visited = new bool[V];
 for(int i=0;i<V;i++)
  visited[i] = false;
 
 if (visited[0] == false)
  {
   myQueue.push(0);
   visited[0] = true;
   while (!myQueue.empty()) 
    {
     list<int>::iterator i;
     int node = myQueue.front();
     for (i = adjList[node].begin(); i != adjList[node].end(); i++) 
     {
      if (!visited[*i])
      {
       cout << *i <<endl;
       visited[*i] = true;
       myQueue.push(*i);
      }
     }
      myQueue.pop();
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
	
 cout << "BFS for the given graph:" << endl; 
 g.BFS1(g); 
return 0; 
}
