#include <iostream>
#include <algorithm>
#include <vector>

struct Vertice {
    int dist;
    int vertice;

    Vertice(int dist, int vertice) {
        this->dist = dist;
        this->vertice = vertice;
    }
};

struct MinHeap {
    std::vector<Vertice> m_data;

    bool compare(Vertice a, Vertice b) {
        return a.dist < b.dist;
    }

    bool empty() {
        return m_data.empty();
    }

    void siftDown(int i) {
        while (true) {
            int child = 2 * i + 1;
            if (child >= m_data.size()) {
                break;
            }
            if (child + 1 < m_data.size() && compare(m_data[child + 1], m_data[child])) {
                ++child;
            }
            if (compare(m_data[child], m_data[i])) {
                std::swap(m_data[i], m_data[child]);
                i = child;
            } else {
                break;
            }
        }
    }

    void siftUp(int i) {
        while (compare(m_data[i], m_data[(i - 1) / 2])) {
            std::swap(m_data[i], m_data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    Vertice extractMin() {
        Vertice min = m_data[0];
        m_data[0] = m_data[m_data.size() - 1];
        m_data.pop_back();
        siftDown(0);
        return min;
    }

    void insert(Vertice value) {
        m_data.push_back(value);
        siftUp(m_data.size() - 1);
    }

    void decreaseDist(int vertice, int dist) {
        for (int i = 0; i < m_data.size(); ++i) {
            if (m_data[i].vertice == vertice) {
                m_data[i].dist = dist;
                return siftUp(i);
            }
        }
    }
};

std::vector<int> dijkstra(std::vector<std::vector<int>> weights, int source) {
    MinHeap heap;
    std::vector<int> used(weights.size(), false);
    std::vector<int> dist(weights.size(), INT_MAX / 2);
    for (int i = 0; i < weights.size(); ++i) {
        heap.insert(Vertice(INT_MAX, i));
    }
    heap.decreaseDist(source, 0);
    dist[source] = 0;
    while(!heap.empty()) {
        Vertice vertice = heap.extractMin();
        for (int i = 0; i < weights.size(); ++i) {
            if (weights[vertice.vertice][i] == -1 || i == vertice.vertice || used[i]) {
                continue;
            }
            if (dist[i] > dist[vertice.vertice] + weights[vertice.vertice][i]) {
                dist[i] = dist[vertice.vertice] + weights[vertice.vertice][i];
                heap.decreaseDist(i, dist[i]);
            }
        }
        used[vertice.vertice] = true;
    }
    return dist;
}

int main() {
    int vertices_total, edges_total;
    std::cin >> vertices_total >> edges_total;
    std::vector<std::vector<int>> graph(vertices_total, std::vector<int>(vertices_total, -1));
    for (int i = 0; i < edges_total; ++i) {
        int from, to, dist;
        std::cin >> from >> to >> dist;
        graph[from - 1][to - 1] = dist;
    }
    int dist = dijkstra(graph, 0)[vertices_total - 1];
    if (dist < INT_MAX / 2) {
        std::cout << dist;
    } else {
        std::cout << -1;
    }
    return 0;
}
