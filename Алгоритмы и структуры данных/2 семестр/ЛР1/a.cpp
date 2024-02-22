#include <iostream>
#include <vector>
#include <algorithm>

void dfs(std::vector<std::vector<int>> &graph, std::vector<int> &visited, std::vector<int> &answer, int vertex) {
    visited[vertex] = true;
    for (int i = 0; i < graph[vertex].size(); ++i) {
        if (!visited[graph[vertex][i]]) {
            dfs(graph, visited, answer, graph[vertex][i]);
        }
    }
    answer.push_back(vertex);
}

std::vector<int> top_sort(std::vector<std::vector<int>> &graph) {
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

int main() {
    int vertices_num, edges_num;
    std::cin >> vertices_num >> edges_num;
    std::vector<std::vector<int>> graph(vertices_num, std::vector<int>());
    for (int i = 0; i < edges_num; ++i){
        int from, to;
        std::cin >> from >> to;
        graph[from - 1].push_back(to - 1);
    }
    std::vector<int> sorted_gifts = top_sort(graph);
    std::vector<int> answer(graph.size());
    for (int i = 0; i < sorted_gifts.size(); ++i) {
        answer[sorted_gifts[i]] = i + 1;
    }
    for (int i = 0; i < answer.size(); ++i) {
        std::cout << answer[i] << ' ';
    }
    return 0;
}
