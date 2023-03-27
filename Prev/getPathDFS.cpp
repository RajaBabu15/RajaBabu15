#include <iostream>
using namespace std;
#include <queue>
#include <string>

bool allVisited(bool *visited, int n)
{
    for (int i = 0; i < n; i++)
        if (!visited[i])
            return false;
    return true;
}

bool getPath(int **edges, int n, int sv, int ev, bool *visited, vector<int> path)
{
    if (allVisited(visited, n))
        return false;
    if (sv == ev)
    {
        path.push_back(sv);
        return true;
    }
    for (int i = 0; i < n; i++)
    {
        if (!visited[i] && i != sv)
        {
            visited[i] = true;
            if (getPath(edges, n, i, ev, visited, path))
            {
                path.push_back(i);
                return true;
            }
        }
    }
    return false;
}

int main()
{
    // Write your code here
    int n, e;
    cin >> n >> e;
    int **edges = new int *[n];
    for (int i = 0; i < n; i++)
    {
        edges[i] = new int[n];
        for (int j = 0; j < n; j++)
            edges[i][j] = 0;
    }
    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }
    bool *visited = new bool[n];
    for (int i = 0; i < n; i++)
        visited[i] = false;
    int sv, ev;
    cin >> sv >> ev;

    vector<int> path;
    if (getPath(edges, n, sv, ev, visited, path))
    {
        for (int i = 0; i < path.size(); i++)
        {
            cout << path.at(i) << " ";
        }
    }

    for (int i = 0; i < n; i++)
    {
        delete[] edges[i];
    }
    delete[] edges;
    delete[] visited;
}