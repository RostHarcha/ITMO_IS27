#include <iostream>
#include <vector>

struct Worker {
    int64_t rate;
    int64_t busy_to;

    Worker(int64_t _rate, int64_t _busy_to) {
        rate = _rate;
        busy_to = _busy_to;
    }

    ~Worker() {
        // delete &rate;
        // delete &busy_to;
    }
};

struct MinHeapWorkers {
    std::vector<Worker> m_data;
    bool compare_by_rate = false;

    MinHeapWorkers(bool _compare_by_rate) {
        compare_by_rate = _compare_by_rate;
    }

    bool compare(Worker a, Worker b, bool equal = false) {
        if (equal) {
            if (compare_by_rate) {
                return a.rate == b.rate;
            }
            return a.busy_to == b.busy_to;
        }
        if (compare_by_rate) {
            return a.rate < b.rate;
        }
        return a.busy_to < b.busy_to;
    }

    void siftDown(int64_t i) {
        while (true) {
            int64_t child = 2 * i + 1;
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
    void siftUp(int64_t i) {
        while (compare(m_data[i], m_data[(i - 1) / 2])) {
            std::swap(m_data[i], m_data[(i - 1) / 2]);
            i = (i - 1) / 2;
        }
    }

    void buildHeap() {
        for (int64_t i = m_data.size() / 2; i >= 0; --i) {
            siftDown(i);
        }
    }

    Worker extractMin() {
        Worker min = m_data[0];
        m_data[0] = m_data[m_data.size() - 1];
        m_data.pop_back();
        siftDown(0);
        return min;
    }

    void insert(Worker value) {
        m_data.push_back(value);
        siftUp(m_data.size() - 1);
    }
};

int main() {
    int64_t workers_total, orders_total;
    std::cin >> workers_total >> orders_total;
    MinHeapWorkers free_workers(true), busy_workers(false);
    for (int64_t i = 0, rate; i < workers_total; ++i) {
        std::cin >> rate;
        free_workers.m_data.push_back(Worker(rate, 0));
    }
    free_workers.buildHeap();
    int64_t money_spent = 0;
    for (int64_t i = 0, order_created, order_duration; i < orders_total; ++i) {
        std::cin >> order_created >> order_duration;
        while (busy_workers.m_data.size() > 0 && busy_workers.m_data[0].busy_to <= order_created) {
            free_workers.insert(busy_workers.extractMin());
        }
        if (free_workers.m_data.size() > 0) {
            Worker worker(free_workers.extractMin());
            worker.busy_to = order_created + order_duration;
            busy_workers.insert(worker);
            money_spent += order_duration * worker.rate;
        }
    }
    std::cout << money_spent;
    return 0;
}