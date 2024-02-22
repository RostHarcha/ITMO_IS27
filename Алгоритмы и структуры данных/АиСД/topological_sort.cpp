#include <vector>

void dfs(std::vector<std::vector<bool>> &graph, std::vector<int> &visited, std::vector<int> &answer, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < graph.size(); ++i) {
        if (graph[vertex][i] == false) {
            continue;
        }
        if (!visited[i]) {
            dfs(graph, visited, answer, i);
        }
    }
    answer.push_back(vertex);
}

std::vector<int> top_sort(std::vector<std::vector<bool>> &graph) {
    std::vector<int> answer;
    std::vector<int> visited(graph.size(), false);
    for (int i = 0; i < graph.size(); ++i) {
        if (!visited[i]) {
            dfs(graph, visited, answer, i);
        }
    }
    std::reverse(answer.begin(), answer.end());
    return answer;
}
