/*
	Undirected Graph - Adjacency List

	An undirected graph represented as an adjacency list. We use the
	index values 0 to size - 1 to represent the nodes in the graph.
	In a graph, we have a set of vertices and a set of edges.
	An edge connects two vertices. In an undirected graph, the
	order of the two vertices doesn't matter. In this implementation,
	we use a vector array instead of a list array for easier access and
	deletion.

	Read more at https://www.geeksforgeeks.org/graph-and-its-representations/
*/


#include <iostream>
#include <vector>
using namespace std;

void addEdge(vector<int> adj[4], int u, int v)
{
	// since this is an undirected graph, we add a connection to and from both vertices 'u' and 'v'
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void display(const vector<int> adj[4])
{
	for (int i = 0; i < 4; ++i)
	{
		cout << "Vertex " << i << ": ";
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j] << ' ';
		}
		cout << endl;
	}
}

int main()
{
	vector<int> adj[4]; // 4 vertices in this graph

	addEdge(adj, 0, 1);
	addEdge(adj, 0, 2);
	addEdge(adj, 0, 3);
	addEdge(adj, 1, 3);
	addEdge(adj, 2, 3);

	display(adj);



	return 0;
}