#include <bits/stdc++.h>
using namespace std;

const int maxS = 1e+5;
vector<int> adjList[maxS];

void dfs(int node, vector<bool> &visited)
{
    visited[node] = true;
    cout << node << "->";
    for (int i = 0; i < adjList[node].size(); i++)
    {
        if (visited[adjList[node][i]] == false)
        {
            dfs(adjList[node][i], visited);
        }
    }
}

void bfs(int node)
{
    queue<int> q;
    vector<bool> visited(maxS, false);

    q.push(node);
    visited[node] = true;

    while (!q.empty())
    {
        int front = q.front();
        cout << front << "->";
        q.pop();
        for (int i = 0; i < adjList[front].size(); i++)
        {
            if (visited[adjList[front][i]] == false)
            {
                visited[adjList[front][i]] = true;
                q.push(adjList[front][i]);
            }
        }
    }
    cout << endl;
}

int main()
{
    cout << "Enter number of nodes: ";
    int numNodes = 1;
    cin >> numNodes;
    cout << "Enter starting & destination vertices in u v format: ";
    for (int i = 0; i < numNodes; i++)
    {
        int u, v;
        cin >> u >> v;
        adjList[u].push_back(v);
        adjList[v].push_back(u);
    }
    cout << "Enter 1] DFS \n 2] BFS" << endl;
    int choice = 2;
    cin >> choice;
    cout << "Starting Node: ";
    int startNode;
    cin >> startNode;
    if (choice == 1)
    {
        vector<bool> visited(numNodes, false);
        dfs(startNode, visited);
    }
    else
    {
        bfs(startNode);
    }

    return 0;
}