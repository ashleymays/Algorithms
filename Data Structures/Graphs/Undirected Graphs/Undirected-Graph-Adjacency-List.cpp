/*
	Undirected Graph - Adjacency List

	An undirected graph represented as an adjacency list. We use the
	index values 0 to size - 1 to represent the nodes in the graph.
	In a graph, we have a set of vertices and a set of edges.
	An edge connects two vertices. In an undirected graph, the
	order of the two vertices doesn't matter. In this implementation,
	we use a vector array instead of a list array for easier access.

	Read more at https://www.geeksforgeeks.org/graph-and-its-representations/
*/


#include <iostream>
#include <vector>

class Graph
{
private:
	// 'adj' is our adjacency list.
	// We initialize the size with the constructor 'Graph(...)'
	std::vector<std::vector<int>> adj;

public:
	Graph(int n) : adj(n) {}

	void addEdge(int u, int v);
	void display();
};

void Graph::addEdge(int u, int v)
{
	// Since this is an undirected graph, we add an edge to and from both vertices 'u' and 'v'
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::display()
{
	for (int i = 0; i < adj.size(); ++i)
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
	Graph graph(4);

	graph.addEdge(0, 1);
	graph.addEdge(0, 2);
	graph.addEdge(0, 3);
	graph.addEdge(1, 3);
	graph.addEdge(2, 3);

	graph.display();



	return 0;
}
