#include <iostream>
#include <vector>
#include <tuple>
#include <queue>

using namespace std;

class Edge
{
public:
    int vtx;
    int weight;

    Edge(int vtx, int weight)
    {
        this->vtx = vtx;
        this->weight = weight;
    }
};

int N = 7;
vector<vector<Edge>> graph(N, vector<Edge>());

void addedge(int v1, int v2, int wt)
{
    Edge e1(v2, wt);
    Edge e2(v1, wt);
    graph[v1].push_back(e1);
    graph[v2].push_back(e2);
}

void displaygraph()
{
    cout << endl;
    for (int i = 0; i < graph.size(); i++)
    {
        cout << i << " -> ";
        for (Edge e : graph[i])
        {
            cout << " ( " << e.vtx << " , " << e.weight << " ) , ";
        }
        cout << endl;
    }
    cout << endl;
}

// Questions================

/*
================_______   B F S  ____________=======================
*/
// 1. BFS_01---------------------

void BFS_01(int src, vector<bool> &vis)
{

    queue<pair<int, string>> que;
    que.push(make_pair(src, to_string(src) + " "));

    int dest = 6;

    while (que.size() != 0)
    {
        pair<int, string> rvtx = que.front();
        que.pop();

        if (vis[rvtx.first] == true)
        {
            //cycle detected
            cout << "CYCLE:" << rvtx.second << endl;
            continue;
        }

        if (rvtx.first == dest)
        {
            cout << "Destination:" << rvtx.second << endl;
        }

        vis[rvtx.first] = true;

        for (Edge e : graph[rvtx.first])
        {
            if (vis[e.vtx] != true)
            {
                que.push(make_pair(e.vtx, rvtx.second + to_string(e.vtx) + " "));
            }
        }
    }
}

// 2. BFS_02(delimiter Method)---------------------
void BFS_01(int src, vector<bool> &vis)
{
    
}

// 3. BFS_03( store level along with src & string)---------------------
// USING TUPLES---------------------

// 4. BFS_04 (using queue's current size  concept)---------------------

// 5. BFS_05 (don't detect cycles...just give shortest path to thedestination )---------------------
// Best if we just need the path to destination

//___________________ B I P A R T I L E _______________________________

//Basic.==================================================

void constructgraph()
{
    addedge(0, 1, 10);
    addedge(0, 3, 10);
    addedge(1, 2, 10);
    addedge(2, 3, 40);
    addedge(3, 4, 2);
    addedge(4, 5, 2);
    addedge(4, 6, 3);
    addedge(5, 6, 8);

    displaygraph();
}
void solve()
{
    constructgraph();

    vector<bool> vis(N, false);
    // BFS_01(0, vis);
    BFS_02(0,vis);
    //BFS_03(0,vis);
    // BFS_04(0,vis);
    // BFS_05(0,vis);
}

void set1()
{
    solve();
}

int main()
{
    set1();
    return 0;
}