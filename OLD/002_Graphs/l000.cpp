#include <iostream>
#include <vector>

using namespace std;

class Edge
{
public:
    int v;
    int w;

    Edge(int v, int w)
    {
        this->v = v;
        this->w = w;
    }
};

int N = 7;
vector<vector<Edge>> graph(N, vector<Edge>());

void addEdge(int u, int v, int w)
{
    Edge e1(v, w);
    Edge e2(u, w);
    graph[u].push_back(e1);
    graph[v].push_back(e2);
}

void displayGraph()
{
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (Edge e : graph[i])
        {
            cout << "(" << e.v << ", " << e.w << "),";
        }
        cout << endl;
    }
    cout << endl;
}

void constructGraph()
{

    addEdge(0, 1, 10);
    addEdge(0, 3, 10);
    addEdge(1, 2, 10);
    addEdge(2, 3, 40);
    addEdge(3, 4, 2);
    addEdge(4, 5, 2);
    addEdge(4, 6, 3);
    addEdge(5, 6, 8);

    displayGraph();
}

