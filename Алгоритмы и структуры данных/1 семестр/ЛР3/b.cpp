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
class Queue {
  private:
    Node<T>* head;
    Node<T>* tail;
    int length; 
  public:
    Queue() {
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

    T pop_forward() {
        if (this->length == 0) {
            throw "Queue is empty";
        }
        Node<T>* node = this->head;
        this->head = node->next;
        if (this->head == nullptr) {
            this->tail = nullptr;
        } else {
            this->head->prev = nullptr;
        }
        T value = node->value;
        delete node;
        --this->length;
        return value;
    }
};

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    int64_t chat_length, value;
    std::cin >> chat_length;
    Queue<int64_t> chat;
    char action;
    for (int64_t i = 0; i < chat_length; ++i) {
        std::cin >> action;
        if (action == '+') {
            std::cin >> value;
            chat.push_back(value);
        }
        if (action == '-') {
            std::cout << chat.pop_forward() << '\n';
        }
    }
    return 0;
}
