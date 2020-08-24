// Program to print shortest path in an unweighted graph
#include <bits/stdc++.h> 
using namespace std; 

void add_edge(vector<int> adj[], int u, int v) 
{ 
 adj[u].push_back(v); 
 adj[v].push_back(u); 
} 

// A modified version of BFS that stores predecessor of each vertex in array p and its distance from source in array d 
bool BFS(vector<int> adj[], int src, int dest, int v, int pred[], int dist[]) 
{  
 list<int> queue; 
 bool visited[v];  
 for (int i = 0; i < v; i++)
 { 
  visited[i] = false; 
  dist[i] = INT_MAX; 
  pred[i] = -1; 
 } 
 visited[src] = true; 
 dist[src] = 0; 
 queue.push_back(src); 

 while (!queue.empty()) 
 { 
  int u = queue.front(); 
  queue.pop_front(); 
  for (int i = 0; i < adj[u].size(); i++) 
  { 
  if (visited[adj[u][i]] == false) 
  { 
   visited[adj[u][i]] = true; 
   dist[adj[u][i]] = dist[u] + 1; 
   pred[adj[u][i]] = u; 
   queue.push_back(adj[u][i]); 
   if (adj[u][i] == dest) 
    return true; 
   } 
  } 
 }
 return false; 
} 

// function to print the shortest distance between source vertex and destination vertex 
void BFS_SPATH(vector<int> adj[], int s, int dest, int v) 
{ 

 int pred[v], dist[v]; 

 if (BFS(adj, s, dest, v, pred, dist) == false) 
 { 
  cout << "Given source and destination"
  << " are not connected"; 
  return; 
} 

// vector path stores the shortest path 
 vector<int> path; 
 int crawl = dest; 
 path.push_back(crawl); 
 while (pred[crawl] != -1)
 { 
  path.push_back(pred[crawl]); 
  crawl = pred[crawl]; 
 }

// distance from source is in distance array 
cout << "Shortest path length is : "
<< dist[dest]; 

// printing path from source to destination 
 cout << "\nPath is::\n"; 
 for (int i = path.size() - 1; i >= 0; i--) 
   cout << path[i] << " "; 
} 


int main() 
{ 
	int v = 7; 
	vector<int> adj[v]; 
	add_edge(adj, 0, 1); 
	add_edge(adj, 0, 2); 
	add_edge(adj, 1, 3); 
	add_edge(adj, 1, 4); 
	add_edge(adj, 3, 4); 
	add_edge(adj, 4, 6); 
	add_edge(adj, 2, 5); 
	add_edge(adj, 5, 6); 
	int source = 0, dest = 6; 
	BFS_SPATH(adj, source, dest, v); 
	return 0; 
} 
