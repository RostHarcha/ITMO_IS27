#include <iostream>

class Interval {
    private:
    int from = 15;
    int to = 30;
    
    void set_from(int value) {
        if (value > this->from) {
            this->from = value;
        }
    }
    
    void set_to(int value) {
        if (value < this->to) {
            this->to = value;
        }
    }
    
    public:
    void set_value(std::string prefix, int value) {
        if (prefix == ">=") {
            this->set_from(value);
        } else {
            this->set_to(value);
        }
    }
    
    int get_value() {
        if (this->from > this->to) {
            return -1;
        }
        if (this->from > 30) {
            return -1;
        }
        return this->from;
    }
};

void process_subject(int n_experts) {
    Interval interval;
    std::string prefix;
    int value;
    for (int expert = 0; expert < n_experts; ++expert) {
        std::cin >> prefix >> value;
        interval.set_value(prefix, value);
        std::cout << interval.get_value() << '\n';
    }
}

int main() {
    int n_subjects;
    std::cin >> n_subjects;
    for (int i = 0; i < n_subjects; ++i) {
        int n_experts;
        std::cin >> n_experts;
        process_subject(n_experts);
    }
    return 0;
}