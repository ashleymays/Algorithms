/*
	Breadth First Search - Graph

	We implement a Breadth First Search algorithm for a graph.
	For this implementation, we use an undirected graph represented as an adjacency list.

	Time Complexity: O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.
	Space Complexity: O(n) because of the boolean vector.

	Read more at https://www.hackerearth.com/practice/algorithms/graphs/breadth-first-search/tutorial/
*/

#include <iostream>
#include <vector>
#include <queue>

class Graph {
private:
	std::vector<std::vector<int>> adj;

public:
	Graph(int n) : adj(n) {}

	void addEdge(int u, int v);
	void display();
	void BFS(int start);
};

void Graph::addEdge(int u, int v)
{
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


// Breadth First Search
void Graph::BFS(int start)
{
	// Vector of booleans to check what nodes have been visited. Nodes are the indices.
	// Ex: "visited[2] = true" means that the node with value 2 has been visited
	std::vector<bool> visited(adj.size(), false);

	// Queue to keep track of the current node's neighbors (i.e. nodes on the same level).
	std::queue<int> q;

	// Push the starting node into the queue and mark the starting node as visited.
	q.push(start);
	visited[start] = true;
	std::cout << "Starting at: " << start << std::endl;



	int v;
	while (!q.empty())
	{
		// The current node is the next node in the queue.
		v = q.front();
		q.pop();


		std::cout << "Current Node: " << v << std::endl;


		// Read all the neighbors of the current node.
		for (int i = 0; i < adj[v].size(); ++i)
		{
			// If the neighboring node hasn't been visited, add it to the queue.
			if (!visited[adj[v][i]])
			{
				q.push(adj[v][i]);
				visited[adj[v][i]] = true;
				std::cout << "Visited: " << adj[v][i] << std::endl;
			}
		}
	}
}

int main()
{
	Graph graph(6);

	graph.addEdge(0, 4);
	graph.addEdge(0, 2);
	graph.addEdge(4, 3);
	graph.addEdge(2, 1);
	graph.addEdge(2, 5);

	graph.BFS(0);

	return 0;
}