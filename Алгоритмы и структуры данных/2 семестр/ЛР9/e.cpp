#include <iostream>
#include <vector>
#include <algorithm>
#include <set>

struct Graph {
    std::vector<std::vector<int>> graph;

    std::vector<int> enter;
    std::vector<int> ret;
    std::vector<bool> visited;
    std::set<std::pair<int, int>> bridges;
    int time;

    Graph(int vertices_total) {
        graph = std::vector<std::vector<int>>(vertices_total, std::vector<int>());
        time = 0;
        enter = std::vector<int>(graph.size());
        ret = std::vector<int>(graph.size());
        visited = std::vector<bool>(graph.size(), false);
    }

    void add_edge(int u, int v) {
        graph[u].push_back(v);
        graph[v].push_back(u);
    }

    void dfs(int vertex, int from) {
        visited[vertex] = true;
        enter[vertex] = ret[vertex] = time++;
        for (int i = 0; i < graph[vertex].size(); ++i) {
            int to = graph[vertex][i];
            if (to == from) {   
                continue;
            }
            if (visited[to]) {
                ret[vertex] = std::min(ret[vertex], enter[to]);
                continue;
            }
            dfs(to, vertex);
            ret[vertex] = std::min(ret[vertex], ret[to]);
            if (ret[to] > enter[vertex]) {
                bridges.insert(std::pair<int, int>(std::min<int>(vertex, to) + 1, std::max<int>(vertex, to) + 1));
            }
        }
    }

    void find_bridges() {
        for (int i = 0; i < graph.size(); ++i) {
            if (!visited[i]) {
                dfs(i, -1);
            }
        }
    }
};

int main() {
    int vertices_total, edges_total;
    std::cin >> vertices_total >> edges_total;
    Graph graph(vertices_total);
    for (int i = 0; i < edges_total; ++i) {
        int from, to;
        std::cin >> from >> to;
        graph.add_edge(from - 1, to - 1);
    }

    graph.find_bridges();
    for (std::pair<int, int> const &bridge: graph.bridges) {
        std::cout << bridge.first << ' ' << bridge.second << '\n';
    }
    return 0;
}
