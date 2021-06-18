#include <iostream>
#include <vector>
using namespace std;

bool isSafe(vector<vector<int>> &graph, int n, int v, int c, vector<int> &color)
{
    for (int i = 0; i < n; i++)
    {
        if (graph[v][i] == 1 && c == color[i])
        { // if there is an adj node exist and its color is same as c
            return false;
        }
    }
    return true;
}

bool graphColoring(vector<vector<int>> &graph, int m, int n, vector<int> &color, int v)
{
    if (v == n)
    { // base condition: v = total number of vertex
        return true;
    }
    for (int c = 1; c <= m; c++)
    {
        if (isSafe(graph, n, v, c, color))
        {
            color[v] = c;
            if (graphColoring(graph, m, n, color, v + 1))
            {
                return true;
            }
            color[v] = 0;
        }
    }
    return false;
}

bool mColoring(vector<vector<int>> &graph, int m)
{
    vector<int> color(m);
    if (graphColoring(graph, m, graph[0].size(), color, 0))
    {
        for (int i = 0; i < graph[0].size(); i++)
        {
            cout << color[i] << " ";
        }
        return true;
    }
    else
    {
        return false;
    }
}

int main()
{
    int n, m;
    cin >> n;
    vector<vector<int>> graph(n, vector<int>(n));
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
        {
            cin >> graph[i][j];
        }
    }
    cin >> m;
    mColoring(graph, m);
    return 0;
}