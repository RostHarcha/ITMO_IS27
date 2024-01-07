#include <iostream>

template <typename T>
struct Node {
    T value;
    Node* prev = nullptr;
    Node* next = nullptr;
    Node (T value) {
        this->value = value;
    }
};

template <typename T>
class Stack {
  private:
    Node<T>* head;
    Node<T>* tail;
  public:
    int64_t length;

    Stack() {
        this->head = nullptr;
        this->tail = nullptr;
        this->length = 0;
    }

    void push_back(T value) {
        Node<T>* node = new Node<T>(value);
        if (this->length == 0) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        ++this->length;
    }

    T pop_back() {
        Node<T>* node = this->tail;
        this->tail = node->prev;
        if (this->tail == nullptr) {
            this->head = nullptr;
        } else {
            this->tail->next = nullptr;
        }
        T value = node->value;
        delete node;
        --this->length;
        return value;
    }

    T tail_value() {
        return this->tail->value;
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int64_t logs_total;
    std::cin >> logs_total;
    int64_t* logs = new int64_t[logs_total];
    for (int64_t i = 0; i < logs_total; ++i) {
        std::cin >> logs[i];
    }
	Stack<int64_t> stack;
	int64_t max_area = 0;
	int64_t i_max_log;
	int64_t temp_area;
	int64_t log = 0; 
	while (log < logs_total) { 
        if (stack.length == 0 || logs[stack.tail_value()] <= logs[log]) {
            stack.push_back(log++);
        } else {
            i_max_log = stack.pop_back();
            if (stack.length == 0) {
                temp_area = logs[i_max_log] * log;
            } else {
                temp_area = logs[i_max_log] * (log - stack.tail_value() - 1);
            }
            if (max_area < temp_area) {
                max_area = temp_area;
            }
        }
	}
    while (stack.length > 0) {
        i_max_log = stack.pop_back();
        if (stack.length == 0) {
            temp_area = logs[i_max_log] * log;
        } else {
            temp_area = logs[i_max_log] * (log - stack.tail_value() - 1);
        }
        if (max_area < temp_area) {
            max_area = temp_area;
        }
    }
    std::cout << max_area;
    delete[] logs;
	return 0; 
}
