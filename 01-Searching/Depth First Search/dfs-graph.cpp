/*
	Depth First Search - Graph

	We implement a Depth First Search algorithm for a graph.
	For this implementation, we use an undirected graph represented as an adjacency list.

	Time Complexity: O(|V| + |E|), where |V| is the number of vertices and |E| is the number of edges.

	Read more at https://www.hackerearth.com/practice/algorithms/graphs/depth-first-search/tutorial/
*/

#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class Graph {
private:
	vector<vector<int>> adj;

public:
	Graph(int n) : adj(n) {}

	void addEdge(int u, int v);
	void display();
	void DFS(int start);
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
		cout << "Vertex " << i << ": ";
		for (int j = 0; j < adj[i].size(); ++j)
		{
			cout << adj[i][j] << ' ';
		}
		cout << endl;
	}
}


// Depth First Search
void Graph::DFS(int start)
{
	// Vector of booleans to check what vertices have been visited. Vertices are the indices.
	// Ex: "visited[2] = true" means that the vertex with value 2 has been visited
	vector<bool> visited(adj.size(), false);

	// Stack to keep track of the current vertex's neighbors (i.e. nodes on the same level).
	stack<int> s;

	// Push the starting node into the stack and mark the starting vertex as visited.
	s.push(start);
	visited[start] = true;
	cout << "Starting at: " << start << endl;



	int v;
	while (!s.empty())
	{
		// The current vertex is the next vertex in the stack.
		v = s.top();
		s.pop();

		if (!visited[v])
		{
			visited[v] = true;
		}


		cout << "Current Vertex: " << v << endl;


		// Read all the neighbors of the current vertex.
		for (int i = 0; i < adj[v].size(); ++i)
		{
			// If the neighboring vertex hasn't been visited, add it to the stack.
			if (!visited[adj[v][i]])
			{
				s.push(adj[v][i]);
				cout << "Visited: " << adj[v][i] << endl;
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

	graph.DFS(0);

	return 0;
}