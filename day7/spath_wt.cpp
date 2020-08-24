//Program to find shortest path using BFS in Weighted Graphs (Dijkstra's Algo)
//Adjacency matrix representation of the graph is used because Graph is weighted 

#include<iostream>
#include<climits>     
using namespace std;
#define SIZE 6

// This function returns a minimum distance for the vertex which is not included in Tset.
 int minimumDist(int dist[], bool Tset[]) 
 {
  int min=INT_MAX,index;
              
  for(int i=0;i<6;i++) 
  {
   if(Tset[i]==false && dist[i]<=min)      
   {
    min=dist[i];
    index=i;
   }
  }
return index;
}

 void BFS_SPATH(int graph[SIZE][SIZE],int src)
 {
  int dist[SIZE]; // integer array to calculate minimum distance for each node.                            
  bool Tset[SIZE];// boolean array to mark visted/unvisted for each node.
	
 // set the nodes with infinity distance except for the initial node and mark them unvisited.  
  for(int i = 0; i<SIZE; i++)
  {
   dist[i] = INT_MAX;
   Tset[i] = false;	
  }
	
 dist[src] = 0;   // Source vertex distance is set to zero.             
	
 for(int i = 0; i<SIZE; i++)                           
 {
  int m=minimumDist(dist,Tset); // vertex not yet included.
  Tset[m]=true;// m with minimum distance included in Tset.
  for(int i = 0; i<SIZE; i++)                  
  {
  // Updating the minimum distance for the particular node.
   if(!Tset[i] && graph[m][i] && dist[m]!=INT_MAX && dist[m]+graph[m][i]<dist[i])
     dist[i]=dist[m]+graph[m][i];
  }
 }
  cout<<"Vertex\t\tDistance from source"<<endl;
  for(int i = 0; i<SIZE; i++)                      
  { 
   char str=65+i; // Ascii values for pritning A,B,C..
   cout<<str<<"\t\t\t"<<dist[i]<<endl;
  }
 }

int main()
{
int graph[SIZE][SIZE]={ {0,10,20,0,0,0},
			{0,0,0,50,10,0},
			{0,0,0,20,33,0},
			{0,0,0,0,20,2},
			{0,0,0,0,0,1},
			{0,0,0,0,0,0}};
BFS_SPATH(graph,0);
return 0;	                        
}

