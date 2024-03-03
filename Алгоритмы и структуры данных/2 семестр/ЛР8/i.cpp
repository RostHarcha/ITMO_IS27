#include <iostream>
#include <vector>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &color, int vertex, int parent, int &cycles) {
    color[vertex] = 1;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i] != parent) {
            if (color[graph[vertex][i]] == 0) {
                dfs(graph, color, graph[vertex][i], vertex, cycles);
            }
            if (color[graph[vertex][i]] == 1) {
                ++cycles;
            }
        }
    }
    color[vertex] = 2;
}

bool is_hydra(std::vector<std::vector<int>> &graph) {
    int cycles = 0;
    int component_counter = 0;
    std::vector<int> color(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            ++component_counter;
            dfs(graph, color, i, -1, cycles);
        }
    }
    return (cycles == 1 && component_counter == 1);
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
    if (is_hydra(graph)) {
        std::cout << "ARCHIMEDES";
    } else {
        std::cout << "EUCLID";
    }
    return 0;
}
