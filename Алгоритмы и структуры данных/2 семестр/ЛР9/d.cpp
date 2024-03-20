#include <iostream>
#include <vector>
#include <algorithm>

std::vector<std::vector<uint64_t>> WFI(std::vector<std::vector<uint64_t>> graph) {
    for (int i = 0; i < graph.size(); ++i) {
        for (int j = 0; j < graph.size(); ++j) {
            for (int k = 0; k < graph.size(); ++k) {
                if (graph[j][i] != UINT64_MAX && graph[i][k] != UINT64_MAX && graph[j][k] > graph[j][i] + graph[i][k]) {
                    graph[j][k] = graph[j][i] + graph[i][k];
                }
            }
        }
    }
    return graph;
}

int main() {
    int vertices_total, edges_total;
    std::cin >> vertices_total >> edges_total;
    std::vector<std::vector<uint64_t>> graph(vertices_total, std::vector<uint64_t>(vertices_total, UINT64_MAX));
    for (int i = 0; i < vertices_total; ++i) {
        graph[i][i] = 0;
    }
    for (int i = 0; i < edges_total; ++i) {
        int from, to;
        uint64_t length;
        std::cin >> from >> to >> length;
        graph[from - 1][to - 1] = std::min(graph[from - 1][to - 1], length);
        graph[to - 1][from - 1] = std::min(graph[to - 1][from - 1], length);
    }
    graph = WFI(graph);
    uint64_t min_sum = UINT64_MAX;
    uint64_t min_vertice;
    for (int i = 0; i < vertices_total; ++i) {
        uint64_t sum = 0;
        for (int j = 0; j < vertices_total; ++j) {
            sum += graph[i][j];
        }
        if (sum < min_sum) {
            min_sum = sum;
            min_vertice = i;
        }
    }
    std::cout << min_vertice + 1;
    return 0;
}
