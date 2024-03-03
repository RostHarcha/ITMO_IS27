#include <iostream>
#include <vector>
#include <string>
#include <stack>

void dfs1(std::vector<std::vector<int>> &graph, std::vector<bool> &visited, std::stack<int> &stack, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (!visited[graph[vertex][i]]) {
            dfs1(graph, visited, stack, graph[vertex][i]);
        }
    }
    stack.push(vertex);
}

void dfs2(std::vector<std::vector<int>> &graph, std::vector<int> &component, int component_num, int vertex) {
    component[vertex] = component_num;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (component[graph[vertex][i]] == -1) {
            dfs2(graph, component, component_num, graph[vertex][i]);
        }
    }
}

std::vector<int> find_strong_conn_components(std::vector<std::vector<int>> &graphG) {
    std::vector<bool> visited(graphG.size(), false);
    std::stack<int> stack;
    std::vector<int> component(graphG.size(), -1);
    std::vector<std::vector<int>> graphH(graphG.size(), std::vector<int>());
    for (int i = 0; i < graphG.size(); ++i) {
        for (int j = 0; j < graphG[i].size(); ++j) {
            graphH[graphG[i][j]].push_back(i);
        }
    }
    for (int i = 0; i < graphG.size(); ++i) {
        if (!visited[i]) {
            dfs1(graphG, visited, stack, i);
        }
    }
    int component_counter = 0;
    while (!stack.empty()) {
        int vertex = stack.top();
        stack.pop();
        if (component[vertex] == -1) {
            dfs2(graphH, component, component_counter, vertex);
            ++component_counter;
        }
    }
    return component;
}

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    int vertices_total, edges_total, requests_total;
    std::cin >> vertices_total >> edges_total >> requests_total;
    std::vector<std::vector<int>> graph(vertices_total, std::vector<int>());
    int from, to;
    for (int i = 0; i < edges_total; ++i) {
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    std::vector<int> components = find_strong_conn_components(graph);
    for (int i = 0; i < requests_total; ++i) {
        std::cin >> from >> to;
        if (components[from - 1] == components[to - 1]) {
            std::cout << "YES\n";
        } else {
            std::cout << "NO\n";
        }
    }
    return 0;
}
