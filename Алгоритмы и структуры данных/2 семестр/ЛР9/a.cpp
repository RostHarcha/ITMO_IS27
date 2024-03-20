#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &visited, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (!visited[graph[vertex][i]]) {
            dfs(graph, visited, graph[vertex][i]);
        }
    }
}

int main() {
    int vertices_total, edges_total, requests_total;
    std::cin >> vertices_total >> edges_total >> requests_total;
    std::vector<std::vector<int>> graph(vertices_total, std::vector<int>());
    for (int i = 0; i < edges_total; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
        graph[to - 1].push_back(from - 1);
    }
    for (int i = 0; i < requests_total; ++i) {
        char request;
        int from, to;
        std::cin >> request >> from >> to;
        if (request == '?') {
            std::vector<int> visited(graph.size(), false);
            dfs(graph, visited, from - 1);
            if (visited[to - 1]) {
                std::cout << "YES\n";
            } else {
                std::cout << "NO\n";
            }
        } else {
            for (int j = 0; j < graph[from - 1].size(); ++j) {
                if (graph[from - 1][j] == to - 1) {
                    graph[from - 1].erase(graph[from - 1].cbegin() + j);
                    break;
                }
            }
            for (int j = 0; j < graph[to - 1].size(); ++j) {
                if (graph[to - 1][j] == from - 1) {
                    graph[to - 1].erase(graph[to - 1].cbegin() + j);
                    break;
                }
            }
        }
    }
    return 0;
}
