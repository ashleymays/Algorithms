/*
    Weighted Undirected Graph

    This is an undirected graph that adds values to edges. In applications, these values can
    represent physical distances in maps or the potential accuracy of recommendations in social media.
    This particular graph is represented as an adjacency list where we have a vector that contains 'n'
    vectors filled with pairs. The pairs will contain the connected vertex and the weight of the edge.

    Read more at https://www.codewars.com/kata/5aaea7a25084d71006000082
*/

#include <iostream>
#include <vector>

class Graph
{
private:
    std::vector<std::vector<std::pair<int, int>>> adj;
public:
    Graph(int n) : adj(n, std::vector<std::pair<int, int>>()) {}

    void addEdge(int u, int v, int w);
    void display();
};

// Add an edge between vertices u and v. The edge has weight w.
void Graph::addEdge(int u, int v, int w)
{
    adj[u].push_back(std::make_pair(v, w));
    adj[v].push_back(std::make_pair(u, w));
}

// Display the graph.
void Graph::display()
{
    for (int i = 0; i < adj.size(); ++i)
    {
        std::cout << "Vertex " << i << ": ";
        for (int j = 0; j < adj[i].size(); ++j)
        {
            // display the vertex it's connected to and the weight of the edge
            std::cout << '(' << adj[i][j].first << ',' << adj[i][j].second << ')' << " ";
        }
        std::cout << std::endl;
    }
}

int main()
{
    Graph g(4);

    g.addEdge(0, 1, 5);
    g.addEdge(0, 2, 10);
    g.addEdge(1, 3, 15);
    g.addEdge(2, 3, 12);
    g.addEdge(0, 3, 11);

    g.display();

    return 0;
}