#include <vector>

void visit(std::vector<std::vector<bool>> &graph, std::vector<int> &colors, int vertex) {
    colors[vertex] = 1;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[vertex][i] == false) {
            continue;
        }
        if (colors[i] == 0) {
            visit(graph, colors, i);
        }
    }
    colors[vertex] = 2;
}

void dfs(std::vector<std::vector<bool>> &graph) {
    std::vector<int> colors(graph.size(), 0);
    for (int i = 0; i < graph.size(); ++i) {
        if (colors[i] == 0) {
            visit(graph, colors, i);
        }
    }
}
