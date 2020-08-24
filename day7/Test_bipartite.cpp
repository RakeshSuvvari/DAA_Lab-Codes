#include <iostream> 
#include <queue> 
#define V 4 
#define src 0 //Change this value to change the src point of the algorithm
using namespace std;
bool test_bipartite(int G[][V]) 
{
  int colorArr[V]; 
/*The value '-1' of colorArr[i] is used to indicate that no color is assigned to vertex 'i'. The value 1 is used to indicate first color is assigned and value 0 indicates second color is assigned.*/ 
 for (int i = 0; i < V; ++i) 
  colorArr[i] = -1; 
 
 colorArr[src] = 1; 
 queue <int> q; 
 q.push(src); 
 while (!q.empty()) 
  {  
   int u = q.front(); 
   q.pop();  
    if (G[u][u] == 1)
       return false;  
  for (int v = 0; v < V; ++v) 
   { 
    if (G[u][v] && colorArr[v] == -1) 
     { 
      colorArr[v] = 1 - colorArr[u]; 
      q.push(v); 
     } 
    else if (G[u][v] && colorArr[v] == colorArr[u]) 
     return false; 
    }
  } 
 return true; 
} 
  
int main() 
{ 
 int G[][V] = {	{0, 1, 0, 1}, 
                {1, 0, 1, 0}, 
        	{0, 1, 0, 1}, 
        	{1, 0, 1, 0} }; 
  
    test_bipartite(G) ? cout << "Yes\n" : cout << "No\n"; 
    return 0; 
} 
