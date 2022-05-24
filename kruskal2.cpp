#include <bits/stdc++.h>
using namespace std;

const int MAX = 1e6 - 1;
int root[MAX];

int parent(int a)
{
    while (root[a] != a)
    {
        root[a] = root[root[a]];
        a = root[a];
    }
    return a;
}

void union_find(int a, int b)
{
    int d = parent(a);
    int e = parent(b);
    root[d] = root[e];
}

int kruskalMST(pair<int, pair<int, int>> *edgesList, int edgesCount)
{
    int a, b;
    int cost = 0, minCost = 0;
    for (int i = 0; i < edgesCount; i++)
    {
        a = edgesList[i].second.first;
        b = edgesList[i].second.second;

        cost = edgesList[i].first;

        if (parent(a) != parent(b))
        {
            minCost += cost;
            union_find(a, b);
        }
    }

    return minCost;
}

int main()
{
    int vertexCount = 4;
    // cout << "Vertex Count: " << endl;
    // cin >> vertexCount;

    int edgesCount = 5;
    // cout << "Edges Count: " << endl;
    // cin >> edgesCount;

    for (int i = 0; i < MAX; ++i) // initialize the array groups
    {
        root[i] = i;
    }

    pair<int, pair<int, int>> edgesList[edgesCount];
    // for (int i = 0; i < edgesCount; i++)
    // {
    //     int u, v, w;
    //     cin >> u >> v >> w;
    //     edgesList[i] = make_pair(w, make_pair(u, v));
    // }

    edgesList[0] = make_pair(10, make_pair(0, 1));
    edgesList[1] = make_pair(18, make_pair(1, 2));
    edgesList[2] = make_pair(13, make_pair(2, 3));
    edgesList[3] = make_pair(21, make_pair(0, 2));
    edgesList[4] = make_pair(22, make_pair(1, 3));

    sort(edgesList, edgesList + edgesCount);

    cout << "Min cost: " << kruskalMST(edgesList, edgesCount) << endl;

    return 0;
}