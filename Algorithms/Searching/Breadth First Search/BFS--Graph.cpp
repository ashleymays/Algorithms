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
	std::vector<int>* adj;
	int numberOfVertices;
public:
	Graph() : adj(nullptr), numberOfVertices(0) {}
	Graph(int n) : adj(new std::vector<int>[n]), numberOfVertices(n) {}
	~Graph();
	void addEdge(int u, int v);
	void display();
	void BFS(int start);
};

Graph::~Graph()
{
	delete[] adj;
}

void Graph::addEdge(int u, int v)
{
	adj[u].push_back(v);
	adj[v].push_back(u);
}

void Graph::display()
{
	for (int i = 0; i < numberOfVertices; ++i)
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
	std::vector<bool> visited(numberOfVertices, false);

	// Queue to keep track of the current node's neighbors (i.e. nodes on the same level).
	std::queue<int> q;

	// Push the starting node into the queue and mark the starting node as visited.
	q.push(start);
	visited[start] = true;
	std::cout << "Starting at: " << start << std::endl;



	int currentNode;
	while (!q.empty())
	{
		// The current node is the next node in the queue.
		currentNode = q.front();
		q.pop();


		std::cout << "Current Node: " << currentNode << std::endl;


		// Read all the neighbors of the current node.
		for (int i = 0; i < adj[currentNode].size(); ++i)
		{
			// If the neighboring node hasn't been visited, add it to the queue.
			if (!visited[adj[currentNode][i]])
			{
				q.push(adj[currentNode][i]);
				visited[adj[currentNode][i]] = true;
				std::cout << "Visited: " << adj[currentNode][i] << std::endl;
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