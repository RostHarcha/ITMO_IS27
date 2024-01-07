#include <iostream>

int main() {
    const int ENG_ALPHABET_SIZE = 26;
    int messages_total, message_length, sorts_total, digit, position;
    std::cin >> messages_total >> message_length >> sorts_total;
    char** messages = new char*[messages_total];
    char** temp = new char*[messages_total];
    for (int i = 0; i < messages_total; ++i) {
        messages[i] = new char[message_length];
        temp[i] = new char[message_length];
        for (int j = 0; j < message_length; ++j) {
            std::cin >> messages[i][j];
        }
    }
    int alphabet[ENG_ALPHABET_SIZE];
    for (int sort = 0; sort < sorts_total; ++sort) {
        digit = message_length - sort - 1;
        for (int i = 0; i < ENG_ALPHABET_SIZE; ++i) {
            alphabet[i] = 0;
        }
        for (int i = 0; i < messages_total; ++i) {
            ++alphabet[messages[i][digit] - 'a'];
        }
        for (int i = 1; i < ENG_ALPHABET_SIZE; ++i) {
            alphabet[i] += alphabet[i - 1];
        }
        for (int i = messages_total - 1; i >= 0; --i) {
            position = alphabet[messages[i][digit] - 'a'] - 1;
            for (int j = 0; j < message_length; ++j) {
                temp[position][j] = messages[i][j];
            }
            --alphabet[messages[i][digit] - 'a'];
        }
        for (int i = 0; i < messages_total; ++i) {
            for (int j = 0; j < message_length; ++j) {
                messages[i][j] = temp[i][j];
            }
        }
    }
    for (int i = 0; i < messages_total; ++i) {
        std::cout << messages[i] << '\n';
        delete[] messages[i];
        delete[] temp[i];
    }
    delete[] messages;
    delete[] temp;
    return 0;
}
