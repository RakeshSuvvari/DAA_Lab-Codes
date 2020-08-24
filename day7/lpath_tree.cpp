// C++ program to find longest path of the tree 
#include "graph.h"
#include<cstring>

// method returns farthest node and its distance from node u 
pair<int, int> Graph::LPATH(int u) 
{ 
	// mark all distance with -1 
	int dis[V]; 
	memset(dis, -1, sizeof(dis)); 

	queue<int> q; 
	q.push(u); 

	// distance of u from u will be 0 
	dis[u] = 0; 

	while (!q.empty()) 
	{ 
		int t = q.front();	 q.pop(); 

		// loop for all adjacent nodes of node-t 
		for (auto it = adjList[t].begin(); it != adjList[t].end(); it++) 
		{ 
			int v = *it; 

			// push node into queue only if 
			// it is not visited already 
			if (dis[v] == -1) 
			{ 
				q.push(v); 

				// make distance of v, one more 
				// than distance of t 
				dis[v] = dis[t] + 1; 
			} 
		} 
	} 

	int maxDis = 0; 
	int nodeIdx; 

	// get farthest node distance and its index 
	for (int i = 0; i < V; i++) 
	{ 
		if (dis[i] > maxDis) 
		{ 
			maxDis = dis[i]; 
			nodeIdx = i; 
		} 
	} 
	return make_pair(nodeIdx, maxDis); 
} 

// method prints longest path of given tree 
void Graph::printLPATH() 
{ 
	pair<int, int> t1, t2; 

	// first bfs to find one end point of 
	// longest path 
	t1 = LPATH(0); 

	// second bfs to find actual longest path 
	t2 = LPATH(t1.first); 

	cout << "Longest path is from " << t1.first << " to "
		<< t2.first << " of length " << t2.second << "\n"; 
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
	g.printLPATH(); 
	return 0; 
} 

