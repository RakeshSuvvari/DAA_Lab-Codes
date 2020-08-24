//Program to perform DFS of a graph from a vertex given by user
//Program also checks if another vertex(given by user) is reachable from intial vertex
#include "graph.h"
#include<algorithm>
 
void Graph::DFS3(Graph G,int s,int t)
{

 visited[s] = true;
 list<int> adjLists = adjList[s];
 cout << s << " ";
 
list<int>::iterator i;
 for(i = adjLists.begin(); i != adjLists.end(); ++i)
   if(!visited[*i])
     DFS3(G,*i,t);
   if(find(adjLists.begin(),adjLists.end(),t)!=adjLists.end())
     cout << "\nReachable";
   else
     cout << "\nNot Reachable";
     // Note : The last output of reachability is the correct output
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
 g.DFS3(g,1,2);
return 0;
}
