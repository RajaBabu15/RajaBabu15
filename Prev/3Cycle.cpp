#include <iostream>
#include <vector>
#include <bits/stdc++.h>
using namespace std;

void getStart(int **edges, int n, int num,
              vector<pair<int, int>> &start)
{
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            if (edges[i][j] == num)
            {
                pair<int, int> p;
                p.first = i;
                p.second = j;
                start.push_back(p);
            }
        }
    }
}

int get3Cycle(int **edges, int n, int start, int end, int **visited)
{
    visited[start][end] = 1;
    int count = 0;
    for (int i = 0; i < n; i++)
    {
        if (i != start && i != end && edges[end][i] == 1 && visited[end][i] == 0 && edges[i][start] == 1 && visited[i][start] == 0)
        {
            count++;
        }
    }
    return count;
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
        {
            edges[i][j] = 0;
        }
    }

    for (int i = 0; i < e; i++)
    {
        int f, s;
        cin >> f >> s;
        edges[f][s] = 1;
        edges[s][f] = 1;
    }

    vector<pair<int, int>> starts;
    getStart(edges, n, 1, starts);

    int **visited = new int *[n];
    for (int i = 0; i < n; i++)
    {
        visited[i] = new int[n];
        for (int j = 0; j < n; j++)
            visited[i][j] = 0;
    }

    int cycle_of_three = 0;

    for (int i = 0; i < starts.size(); i++)
    {
        cycle_of_three += get3Cycle(edges, n, starts[i].first, starts[i].second, visited);
    }

    return cycle_of_three;
}