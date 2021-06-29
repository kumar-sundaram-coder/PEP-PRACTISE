#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
    int v; // vtx
    int w; //weight

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

void addEdge(vector<vector<Edge>> &graph, int u, int v, int w)
{
    Edge e1(v, w);
    Edge e2(u, w);

    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

void displayGraph(vector<vector<Edge>> &graph)
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";

        for (Edge e : graph[i])
        {
            cout << "(" << e.v << ", " << e.w << "), ";
        }
        cout << endl;
    }
    cout << endl;
}

void constructGraph()
{
    int N = 7;
    vector<vector<Edge>> graph(N, vector<Edge>());

    addEdge(graph, 0, 1, 10);
    addEdge(graph, 0, 3, 10);
    addEdge(graph, 1, 2, 10);
    addEdge(graph, 2, 3, 40);
    addEdge(graph, 3, 4, 2);
    addEdge(graph, 4, 5, 2);
    addEdge(graph, 4, 6, 3);
    addEdge(graph, 5, 6, 8);

    displayGraph(graph);
}

void set1()
{
}

void solve()
{
    constructGraph();
    set1();
}

int main()
{
    solve();
    return 0;
}