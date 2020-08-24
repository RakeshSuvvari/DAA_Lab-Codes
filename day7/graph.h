#include <iostream> 
#include <list> 
#include<queue>
using namespace std;
   
class Graph 
{ 
 int V;     
 list<int> *adjList; 
 bool *visited;     
  public: 
   Graph(int V)
    {
     this->V = V; 
     adjList = new list<int>[V]; 
    } 
    
    void addEdge(int v, int w)
    {
      adjList[v].push_back(w); 
    }
    		
    void DFS_util(int v, bool visited[]);  // A function used by DFS(Graph G)
    void DFS1(Graph G);
    void DFS2(Graph G,int s);
    void DFS3(Graph G,int s,int t);
    		
    void BFS1(Graph G); 
    void BFS2(Graph G,int s);
    void BFS3(Graph G,int s,int t); 
    		
    void AP(int u, bool visited[], int disc[], int low[], int parent[], bool ap[]);
    void test_articulationpoints(Graph G);
    		
    void bridge(int u, bool visited[], int disc[], int low[], int parent[]);
    void test_bridges(Graph G);
    
    
    		   
}; 


