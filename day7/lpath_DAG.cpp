//Program to find Longest Path in  DAG 
#include <iostream> 
#include <limits.h> 
#include <list> 
#include <stack> 
#define NINF INT_MIN 
using namespace std; 

class AdjListNode { 
	int v; 
	int weight; 
	
public: 
	AdjListNode(int _v, int _w) 
	{ 
		v = _v; 
		weight = _w; 
	} 
	int getV() { return v; } 
	int getWeight() { return weight; } 
}; 
	
class Graph { 
	int V; 
	list<AdjListNode>* adj; 
	void tSort(int v, bool visited[],stack<int>& Stack); //Topological Sort
	
public: 
	Graph(int V); // Constructor 
	void addEdge(int u, int v, int weight); 
	void longestPath(int s); 
}; 
	
Graph::Graph(int V) 
{ 
	this->V = V; 
	adj = new list<AdjListNode>[V]; 
} 

void Graph::addEdge(int u, int v, int weight) 
{ 
	AdjListNode node(v, weight); 
	adj[u].push_back(node); 
} 
	
void Graph::tSort(int v, bool visited[], stack<int>& Stack) 
{ 
	// Mark the current node as visited 
	visited[v] = true; 
	
	// Recur for all the vertices adjacent to this vertex 
	list<AdjListNode>::iterator i; 
	for (i = adj[v].begin(); i != adj[v].end(); ++i) { 
		AdjListNode node = *i; 
		if (!visited[node.getV()]) 
			tSort(node.getV(), visited, Stack); 
	} 
	
	// Push current vertex to stack which stores topological 
	// sort 
	Stack.push(v); 
} 
	
void Graph::longestPath(int s) 
{ 
	stack<int> Stack; 
	int dist[V]; 
	
	// Mark all the vertices as not visited 
	bool* visited = new bool[V]; 
	for (int i = 0; i < V; i++) 
		visited[i] = false; 
	for (int i = 0; i < V; i++) 
		if (visited[i] == false) 
			tSort(i, visited, Stack); 
	
	// Initialize distances to all vertices as infinite and 
	// distance to source as 0 
	for (int i = 0; i < V; i++) 
		dist[i] = NINF; 
	dist[s] = 0; 
	
	// Process vertices in topological order 
	while (Stack.empty() == false) { 
		// Get the next vertex from topological order 
		int u = Stack.top(); 
		Stack.pop(); 
	
		// Update distances of all adjacent vertices 
		list<AdjListNode>::iterator i; 
		if (dist[u] != NINF) { 
			for (i = adj[u].begin(); i != adj[u].end(); ++i) 
				if (dist[i->getV()] < dist[u] + i->getWeight()) 
					dist[i->getV()] = dist[u] + i->getWeight(); 
		} 
	}  
	for (int i = 0; i < V; i++) 
		(dist[i] == NINF) ? cout << "INF " : cout << dist[i] << " "; 
	
	delete [] visited; 
} 
	

int main() 
{ 
	Graph g(5); 
	g.addEdge(0, 1, 5); 
	g.addEdge(0, 2, 3); 
	g.addEdge(0, 3, 6); 
	g.addEdge(1, 2, 2); 
	g.addEdge(2, 4, 4);
	g.addEdge(3, 4, 4);
	
	int s = 1; 
	cout << "Following are longest distances from source vertex " << s << " \n"; 
	g.longestPath(s); 
	
	return 0; 
} 

