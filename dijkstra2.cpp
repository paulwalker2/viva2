#include <bits/stdc++.h>
using namespace std;
#define V 4

int minVertex(bool spt[], int dist[])
{
    int min = INT_MAX, min_index = 0;
    for (int v = 0; v < V; v++)
    {
        if (min < dist[v] && spt[v] == false)
        {
            min = dist[v];
            min_index = v;
        }
    }
    return min_index;
}

void printSolution(int dist[])
{
    cout << "Vertex | Shortest Dist" << endl;
    for (int i = 0; i < V; i++)
    {
        cout << i << "  " << dist[i] << endl;
    }
    cout << endl;
}

void dijkstra(int graph[V][V], int src)
{
    bool spt[V];
    int dist[V];

    // initialize
    for (int i = 0; i < V; i++)
    {
        spt[i] = false;
        dist[i] = INT_MAX;
    }

    dist[src] = 0;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minVertex(spt, dist);
        spt[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && spt[v] == false && dist[u] != INT_MAX &&
                dist[u] + graph[u][v] <= dist[v])
            {
                dist[v] = graph[u][v] + dist[u];
            }
        }
    }

    printSolution(dist);
}

int main()
{
    int graph[V][V] = {
        {0, 2, 0, 5},
        {2, 0, 3, 0},
        {0, 3, 0, 4},
        {5, 0, 4, 0},
    };

    dijkstra(graph, 0);
    return 0;
}