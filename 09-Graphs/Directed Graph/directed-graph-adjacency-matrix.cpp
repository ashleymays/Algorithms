/*
	Directed Graph - Adjacency Matrix

	A directed graph represented as an adjacency matrix. We use the
	index values 0 to size - 1 to represent the keys in the graph.
	In a graph, we have a set of vertices and a set of edges.
	An edge connects two vertices. In a directed graph, the
	order of the two vertices matters. We must decide which node
	the edge starts at and what node it should be directed toward.

	Read more at https://agreen17.medium.com/graph-introduction-fd41142b302e
*/

#include <iostream>
#include <vector>

class Graph {
private:
	std::vector<std::vector<bool>> adj; // adjacency matrix represented as a matrix of booleans

public:
	// initialize adjacency matrix with an n x n matrix where all the entries are 'false'
	Graph(int n) : adj(n, std::vector<bool>(n, false)) {}

	void addEdge(int src, int dest);
	void display();
};

void Graph::addEdge(int src, int dest)
{
	// Add an edge starting at node 'src' and going to 'dest'.
	// Since this is a directed graph, we don't add a connection
	// going from 'dest' to 'src'.
	adj[src][dest] = true;
}

void Graph::display()
{
	for (int i = 0; i < adj.size(); ++i)
	{
		for (int j = 0; j < adj.size(); ++j)
		{
			std::cout << adj[i][j] << ' ';
		}
		std::cout << std::endl;
	}
}

int main()
{
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 0);

	g.display();

	return 0;
}