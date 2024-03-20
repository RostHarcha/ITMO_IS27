#include <iostream>
#include <vector>
#include <algorithm>

struct Cycle {
    int size;
    int weight;

    Cycle(int size, int weight) {
        this->size = size;
        this->weight = weight;
    }
};

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &color, int vertex, int parent, int &in_cycle, std::vector<int> &parents) {
    color[vertex] = 1;
    parents[vertex] = parent;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (graph[vertex][i] != parent) {
            if (color[graph[vertex][i]] == 0) {
                dfs(graph, color, graph[vertex][i], vertex, in_cycle, parents);
            }
            if (color[graph[vertex][i]] == 1) {
                in_cycle = vertex;
                parents[graph[vertex][i]] = vertex;
            }
        }
    }
    color[vertex] = 2;
}

Cycle find_cycle(std::vector<std::vector<int>> &graph, std::vector<std::vector<int>> &weights) {
    int in_cycle = -1;
    std::vector<int> color(graph.size(), 0);
    std::vector<int> parents(graph.size(), -1);
    Cycle cycle(0, 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (color[i] == 0) {
            dfs(graph, color, i, -1, in_cycle, parents);
        }
        if (in_cycle != -1) {
            int current = in_cycle;
            cycle.size++;
            do {
                ++cycle.size;
                cycle.weight += weights[parents[current]][current];
                current = parents[current];
            } while (current != in_cycle);
            return cycle;
        }
    }
    return cycle;
}

int main() {
    int graphs_total, max_len;
    std::cin >> graphs_total >> max_len;
    for (int i = 0; i < graphs_total; ++i) {
        int vertices_total, edges_total;
        std::cin >> vertices_total >> edges_total;
        std::vector<std::vector<int>> graph(vertices_total);
        std::vector<std::vector<int>> weights(vertices_total, std::vector<int>(vertices_total, INT_MAX));
        for (int j = 0; j < edges_total; ++j) {
            int from, to, weight;
            std::cin >> from >> to >> weight;
            graph[--from].push_back(--to);
            weights[from][to] = weight;
        }
        Cycle cycle = find_cycle(graph, weights);
        if (cycle.size <= max_len || cycle.weight >= 0) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }

    return 0;
}
