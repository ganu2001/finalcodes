#include <iostream>
#include <bits/stdc++.h>
#include <omp.h>

using namespace std;

void parallel_bfs(vector<vector<int>> graph, int n, int start)
{
    vector<bool> visited(n, false);
    visited[start] = true;

    queue<int> q;
    q.push(start);

    while (!q.empty())
    {
        int curr = q.front();
        cout<<curr<<" ";
        q.pop();

        #pragma omp parallel for
        for(int i = 0 ; i<n ; i++)
        {
            if(graph[curr][i] && !visited[i])
            {
                q.push(i);
                visited[i] = true;
            }

        }
    }
}

int main()
{
    int n = 5;
    vector<vector<int>> graph(n,vector<int>(n,0));

    graph[1][0] = 1;
    graph[0][1] = 1;
    graph[1][2] = 1;
    graph[2][1] = 1;
    graph[1][3] = 1;
    graph[3][1] = 1;
    graph[2][4] = 1;
    graph[4][2] = 1;

    parallel_bfs(graph ,n, 0);

    return 0;

}