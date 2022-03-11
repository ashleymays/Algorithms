/*
	Undirected Graph - Adjacency Matrix

	An undirected graph represented as an adjacency matrix. We use the
	index values 0 to size - 1 to represent the keys in the graph.
	In a graph, we have a set of vertices and a set of edges.
	An edge connects two vertices. In an undirected graph, the
	order of the two vertices doesn't matter.

	Read more at https://www.geeksforgeeks.org/graph-and-its-representations/
*/


#include <iostream>
#include <vector>

void addEdge(std::vector<std::vector<int>>& adj, int u, int v)
{
	// since this is an undirected graph, we add a connection to and from both vertices 'u' and 'v'
	adj[u][v] = 1;
	adj[v][u] = 1;
}

void display(const std::vector<std::vector<int>>& adj)
{
	for (int i = 0; i < 4; ++i)
	{
		std::cout << "Vertex " << i << ": ";
		for (int j = 0; j < adj[i].size(); ++j)
		{
			std::cout << adj[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main()
{
	// Create the adjacency matrix; graph has 4 vertices
	// We initialize the adjacency matrix as a 4 x 4 square matrix
	// filled with 0's. When we add an edge between two nodes, the
	// value will be changed to 1.
	std::vector<std::vector<int>> adj(4, std::vector<int>(4, 0));

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 2, 3);

	display(adj);



	return 0;
}