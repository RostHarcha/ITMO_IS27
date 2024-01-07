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
class LinkedList {
  private:
    Node<T>* head = nullptr;
    Node<T>* tail = nullptr;
    unsigned long long int length = 0; 
  public:
    void push_back(T value) {
        Node<T>* node = new Node<T>(value);
        if (length == 0) {
            this->head = node;
            this->tail = node;
        } else {
            this->tail->next = node;
            node->prev = this->tail;
            this->tail = node;
        }
        ++length;
    }

    void push_forward(T value) {
        Node<T>* node = new Node<T>(value);
        if (length == 0) {
            this->head = node;
            this->tail = node;
        } else {
            this->head->prev = node;
            node->next = this->head;
            this->head = node;
        }
        ++length;
    }

    T pop_back() {
        if (length == 0) {
            return 0;
        }
        Node<T>* node = this->tail;
        this->tail = node->prev;
        if (this->tail == nullptr) {
            this->head = nullptr;
        } else {
            this->tail->next = nullptr;
        }
        T value = node->value;
        delete node;
        --length;
        return value;
    }

    T pop_forward() {
        if (length == 0) {
            return 0;
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
        --length;
        return value;
    }
    
    unsigned long long int get_length() {
        return length;
    }
};

template<typename T>
void swap(T* a, T* b) {
    T temp = *a;
    *a = *b;
    *b = temp;
}

template<typename T>
void add_treasure(LinkedList<T>* inventory, uint64_t inventory_size, T new_treasure) {
    if (inventory->get_length() < inventory_size) {
        inventory->push_back(new_treasure);
        return;
    }
    if (inventory_size == 1) {
        T treasures[2] = {
            new_treasure,
            inventory->pop_back()
        };
        if (treasures[0] > treasures[1]) {
            swap<T>(&treasures[0], &treasures[1]);
        }
        inventory->push_back(treasures[1]);
        return;
    }
    T treasures[3] = {
        new_treasure,
        inventory->pop_back(),
        inventory->pop_forward()
    };
    if (treasures[0] > treasures[1]) {
        swap<T>(&treasures[0], &treasures[1]);
    }
    if (treasures[1] > treasures[2]) {
        swap<T>(&treasures[1], &treasures[2]);
    }
    if (treasures[0] > treasures[1]) {
        swap<T>(&treasures[0], &treasures[1]);
    }
    if (inventory_size > 1) {
        inventory->push_back(treasures[1]);
    }
    inventory->push_back(treasures[2]);
}

#define INVENTORY_TYPE int64_t

int main() {
    std::ios::sync_with_stdio(0);
    std::cin.tie(0);
    std::cout.tie(0);
    uint64_t treasures_total, inventory_size;
    std::cin >> treasures_total >> inventory_size;
    LinkedList<INVENTORY_TYPE>* inventory = new LinkedList<INVENTORY_TYPE>[inventory_size];
    for (uint64_t treasure = 0; treasure < treasures_total; ++treasure) {
        INVENTORY_TYPE new_treasure;
        std::cin >> new_treasure;
        add_treasure<INVENTORY_TYPE>(inventory, inventory_size, new_treasure);
    }
    while (inventory->get_length() > 0) {
        std::cout << inventory->pop_forward() << ' ';
    }
    delete[] inventory;
    return 0;
}
