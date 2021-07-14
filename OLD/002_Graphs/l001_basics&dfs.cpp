#include <iostream>
#include <vector>

using namespace std;

// Basics:- Constructing, Adding Edges and Displaying Graph
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
            cout << "(" << e.v << ", " << e.w << "), ";
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

// Set 1==========================================================

int findEdge(int v1, int v2)
{
    int vtx = -1;

    for (int i = 0; i < graph[v1].size(); i++)
    {
        Edge e = graph[v1][i];
        if (e.v == v2)
        {
            vtx = i;
            break;
        }
    }

    return vtx;
}

void removeEdge(int v1, int v2)
{
    int idx1 = findEdge(v1, v2);
    int idx2 = findEdge(v2, v1);

    graph[v1].erase(graph[v1].begin() + idx1);
    graph[v2].erase(graph[v2].begin() + idx2);
}

void removeVertex(int vtx)
{

    while (graph[vtx].size() != 0)
    {
        Edge e = graph[vtx].back();
        removeEdge(vtx, e.v);
    }
}

void set1()
{
    int idx = findEdge(2, 3);
    cout << idx << endl;
    removeEdge(2, 3);
    displayGraph();
    removeVertex(3);
    cout << endl;
    displayGraph();
}

// Set 2==========================================================

/*
================_______   D F S  ____________=======================
*/
// 1. hasPath---------------------

int hasPath(int src, int des, vector<bool> &vis)
{
    if (src == des)
    {
        return true;
    }

    vis[src] = true;

    bool res = false;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            res = res || hasPath(e.v, des, vis);
        }
    }
    return res;
}

// 2. allPaths---------------------
int allPaths(int src, int des, vector<bool> &vis, int w, string ans)
{
    if (src == des)
    {
        cout << ans << des << " @ " << w << " Weight. " << endl;

        return 1;
    }

    vis[src] = true;
    int count = 0;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            count += allPaths(e.v, des, vis, w + e.w, ans + to_string(src) + " ");
        }
    }

    vis[src] = false;
    return count;
}

// 3. allSolutions---------------------

class allSolutionsPair
{
public:
    int lightWt = 1e7;
    int heavyWt = 0;
    int ceil = 1e7;
    int floor = 0;
};

void allSolutions(int src, int des, vector<bool> &vis, int w, string ans, allSolutionsPair &solutionsPair, int data)
{
    if (src == des)
    {
        solutionsPair.heavyWt = max(solutionsPair.heavyWt, w);
        solutionsPair.lightWt = min(solutionsPair.lightWt, w);

        if (w > data)
        {
            solutionsPair.ceil = min(solutionsPair.ceil, w);
        }

        if (w < data)
        {
            solutionsPair.floor = max(solutionsPair.floor, w);
        }

        return;
    }

    vis[src] = true;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            allSolutions(e.v, des, vis, w + e.w, ans + to_string(src) + " ", solutionsPair, data);
        }
    }

    vis[src] = false;
    return;
}

void preOrder(int src, vector<bool> &vis, int w, string ans)
{
    vis[src] = true;

    cout << ans << " @ " << w << endl;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            preOrder(e.v, vis, w + e.w, ans + to_string(e.v) + " ");
        }
    }
    vis[src] = false;
}
//4. Hamiltonian path and cycle=========================================

void hamintonianPath(int src, int osrc, vector<bool> &vis, int count, string ans)
{
    if (count == vis.size() - 1)
    {
        int idx = findEdge(src, osrc);
        if (idx != -1)
            cout << "Cycle: " + ans + to_string(src) << endl;
        else
            cout << "Path: " + ans + to_string(src) << endl;

        return;
    }

    vis[src] = true;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            hamintonianPath(e.v, osrc, vis, count + 1, ans + to_string(src) + " ");
        }
    }

    vis[src] = false;
}

//5.GET CONNECTED COMPONENTS (GCC) ===========================================

int GCC_DFS(int src, vector<bool> &vis)
{
    vis[src] = true;

    int count = 0;

    for (Edge e : graph[src])
    {
        if (vis[e.v] != true)
        {
            count += GCC_DFS(e.v, vis);
        }
    }
    return count + 1; // adding 1 (+1) of that particular node i.e., src
}

int GCC()
{
    vector<bool> vis(N, false);
    int count = 0;
    int maxSize = 0;

    for (int i = 0; i < N; i++)
    {
        if (vis[i] != true)
        {
            count++;
            maxSize = max(maxSize, GCC_DFS(i, vis));
        }
    }
    cout << "Maximum Size:" << maxSize << endl;
    return count;
}

void set2()
{
    vector<bool> vis(N, false);

    // bool ans = false;
    // ans = hasPath(0, 5, vis);
    // cout << boolalpha << ans;

    // cout << allPaths(0, 5, vis, 0, "");

    // allSolutionsPair solutionsPair;
    // allSolutions(0, 5, vis, 0, "", solutionsPair, 21);
    // cout << solutionsPair.heavyWt << endl
    //      << solutionsPair.lightWt << endl
    //      << solutionsPair.ceil << endl
    //      << solutionsPair.floor << endl;

    // preOrder(2, vis, 0, to_string(0) + " ");

    // hamintonianPath(2, 2, vis, 0, "");
    cout << GCC();
}

void solve()
{
    constructGraph();
    // set1();
    set2();
}

int main()
{
    solve();
    return 0;
}