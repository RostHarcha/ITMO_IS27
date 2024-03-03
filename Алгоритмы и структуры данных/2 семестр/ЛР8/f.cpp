#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

std::vector<int> bfs(std::vector<std::vector<int>> &graph, int source) {
    std::vector<int> dest(graph.size(), INT_MAX);
    dest[source] = 0;
    std::queue<int> queue;
    queue.push(source);
    while (!queue.empty()) {
        int vertex = queue.front();
        queue.pop();
        for (int i = 0; i < graph[vertex].size(); ++i) {
            if (dest[graph[vertex][i]] == INT_MAX) {
                queue.push(graph[vertex][i]);
                dest[graph[vertex][i]] = std::min(dest[graph[vertex][i]], dest[vertex] + 1);
            }
        }
    }
    return dest;
}

int main() {
    int vertices_total, edges_total, days;
    std::cin >> vertices_total >> edges_total >> days;
    std::vector<std::vector<int>> graph(vertices_total, std::vector<int>());
    for (int i = 0; i < edges_total; ++i) {
        int v1, v2;
        std::cin >> v1 >> v2;
        graph[v1 - 1].push_back(v2 - 1);
        graph[v2 - 1].push_back(v1 - 1);
    }
    std::vector<int> dest = bfs(graph, 0);
    bool found = false;
    for (int i = 0; i < dest.size(); ++i) {
        if (dest[i] == days) {
            found = true;
            std::cout << i + 1 << '\n';
        }
    }
    if (!found) {
        std::cout << "NO";
    }
    return 0;
}
