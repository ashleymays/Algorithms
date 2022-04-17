/*
	Directed Graph - Adjacency List

	A directed graph represented as an adjacency list. We use the
	index values 0 to size - 1 to represent the keys in the graph.
	In a graph, we have a set of vertices and a set of edges.
	An edge connects two vertices. 
	
	In a directed graph, the order of the two vertices matters. 
	We must decide which node the edge starts at and what node it 
	should be directed toward.

	Read more at https://agreen17.medium.com/graph-introduction-fd41142b302e
*/

#include <iostream>
#include <vector>

class Graph {
private:
	std::vector<std::vector<int>> adj; // create adjacency list

public:
	// initialize adjacency list with an array of 'n' vectors
	Graph(int n) : adj(n, std::vector<int>()) {}

	void addEdge(int src, int dest);
	void display();
};

void Graph::addEdge(int src, int dest)
{
	// Add an edge starting at node 'src' and going to 'dest'.
	// Since this is a directed graph, we don't add a connection
	// going from 'dest' to 'src'.
	adj[src].push_back(dest);
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
	Graph g(4);

	g.addEdge(0, 1);
	g.addEdge(1, 3);
	g.addEdge(2, 0);

	g.display();

	return 0;
}