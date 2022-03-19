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

class Graph
{
private:
    // 'adj' is our adjacency matrix.
    // We initialize the size with the constructor 'Graph(...)'
    std::vector<std::vector<bool>> adj;

public:
    Graph(int n) : adj(n, std::vector<bool>(n, false)) {}

    void addEdge(int u, int v);
    void display();
};

void Graph::addEdge(int u, int v)
{
    // Since this is an undirected graph, we add an edge to and from both vertices 'u' and 'v'
    adj[u][v] = true;
    adj[v][u] = true;
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
    // Create the adjacency matrix; graph has 4 vertices
    // We initialize the adjacency matrix as a 4 x 4 square matrix
    // filled with 0's. When we add an edge between two nodes, the
    // value will be changed to 1.
    Graph graph(4);

    graph.addEdge(0, 1);
    graph.addEdge(0, 2);
    graph.addEdge(1, 2);
    graph.addEdge(1, 3);
    graph.addEdge(2, 3);

    graph.display();


    return 0;
}