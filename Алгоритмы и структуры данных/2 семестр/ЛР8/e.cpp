#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &color, int vertex, int parent, bool &cycle) {
    color[vertex] = 1;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i] != parent) {
            if (color[graph[vertex][i]] == 0) {
                dfs(graph, color, graph[vertex][i], vertex, cycle);
            }
            if (color[graph[vertex][i]] == 1) {
                cycle = true;
            }
        }
    }
    color[vertex] = 2;
}

bool find_cycle(std::vector<std::vector<int>> &graph) {
    bool cycle = false;
    std::vector<int> color(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            dfs(graph, color, i, -1, cycle);
        }
        if (cycle) {
            break;
        }
    }
    return cycle;
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
    if (find_cycle(graph)) {
        std::cout << "YES";
    } else {
        std::cout << "NO";
    }
    return 0;
}
