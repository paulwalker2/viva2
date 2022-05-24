#include <bits/stdc++.h>
using namespace std;
#define V 4

int minKey(int key[], bool mstSet[])
{
    int min = INT_MAX;
    int min_index = 0;
    for (int i = 0; i < V; i++)
    {
        if (mstSet[i] == false && key[i] < min)
        {
            min = key[i];
            min_index = i;
        }
    }
    return min_index;
}

void printMst(int parent[], int graph[V][V])
{
    cout << "Vertex | Parent | Weight" << endl;
    for (int i = 1; i < V; i++)
    {
        cout << i << "      " << parent[i] << "         " << graph[i][parent[i]] << endl;
    }
    cout << endl;
}

void primsMst(int graph[V][V])
{
    int parent[V];
    int key[V];
    bool mstSet[V];

    for (int i = 0; i < V; i++)
    {
        key[i] = INT_MAX;
        mstSet[i] = false;
    }

    key[0] = 0;
    // mstSet[0] = true;
    parent[0] = -1;

    for (int count = 0; count < V - 1; count++)
    {
        int u = minKey(key, mstSet);
        mstSet[u] = true;

        for (int v = 0; v < V; v++)
        {
            if (graph[u][v] && mstSet[v] == false && graph[u][v] < key[v])
            {
                key[v] = graph[u][v];
                parent[v] = u;
            }
        }
    }

    printMst(parent, graph);
}

int main()
{

    int graph[V][V] = {
        {0, 2, 0, 5},
        {2, 0, 3, 0},
        {0, 3, 0, 4},
        {5, 0, 4, 0},
    };

    primsMst(graph);
    return 0;
}