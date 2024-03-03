#include <iostream>
#include <vector>
#include <string>
#include <stack>

void dfs(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (!visited[graph[vertex][i]]) {
            dfs(graph, visited, graph[vertex][i]);
        }
    }
}

int count_strong_conn_components(std::vector<std::vector<int>> &graph) {
    std::vector<bool> visited(graph.size(), false);
    std::stack<int> stack;
    int component_counter = 0;
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            ++component_counter;
            dfs(graph, visited, i);
        }
    }
    return component_counter;
}

int main() {
    int vertices_total, edges_total;
    std::cin >> vertices_total >> edges_total;
    std::vector<std::vector<int>> graph(vertices_total, std::vector<int>());
    for (int i = 0; i < edges_total; ++i) {
        int v1, v2;
        std::cin >> v1 >> v2;
        graph[v1 - 1].push_back(v2 - 1);
        graph[v2 - 1].push_back(v1 - 1);
    }
    std::cout << count_strong_conn_components(graph);
    
    return 0;
}