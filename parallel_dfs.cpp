#include <iostream>
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void parallel_dfs(vector<vector<int>> graph, vector<bool> &visited , int n, int curr)
{
    visited[curr] = true;
    cout<<curr<<" ";

    #pragma omp parallel
    for (int i = 0; i < n; i++)
    {
        if(graph[curr][i] && !visited[i])
        {
            parallel_dfs(graph , visited ,n ,i);
        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> graph(n, vector<int>(n, 0));

    graph[1][0] = 1;
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;

    vector<bool> visited(n);
    parallel_dfs(graph,visited, n, 0 );


    return 0;
}