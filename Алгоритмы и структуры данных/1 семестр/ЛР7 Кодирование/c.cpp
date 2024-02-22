#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

struct Symbol {
    char symbol;
    int freq;

    Symbol(char c, int f) {
        symbol = c;
        freq = f;
    }

};

std::vector<Symbol> get_alphabet(std::string str) {
    std::sort(str.begin(), str.end());
    std::vector<Symbol> alphabet;
    Symbol symbol(str[0], 1);
    for (int i = 1; i < str.size(); ++i) {
        if (str[i] == symbol.symbol) {
            symbol.freq++;
        } else {
            alphabet.push_back(symbol);
            symbol = Symbol(str[i], 1);
        }
    }
    alphabet.push_back(symbol);
    return alphabet;
}

bool compare_symbols(const Symbol &a, const Symbol &b) {
    return a.symbol < b.symbol;
}

struct HaffmanTree {
    std::vector<Symbol> symbols;
    int freq;
};

bool compare_trees(const HaffmanTree &a, const HaffmanTree &b) {
    return a.freq > b.freq;
}

int main() {
    std::string str;
    std::cin >> str;
    std::vector<Symbol> alphabet = get_alphabet(str);
    std::vector<HaffmanTree> tree;
    for (int i = 0; i < alphabet.size(); ++i) {
        HaffmanTree haffman_tree;
        haffman_tree.symbols.push_back(Symbol(alphabet[i].symbol, 0));
        haffman_tree.freq = alphabet[i].freq;
        tree.push_back(haffman_tree);
    }
    while (tree.size() > 1) {
        std::sort(tree.begin(), tree.end(), compare_trees);
        HaffmanTree haffman_tree;
        haffman_tree.symbols.reserve(tree[tree.size() - 2].symbols.size() + tree[tree.size() - 1].symbols.size());
        haffman_tree.symbols.insert(haffman_tree.symbols.end(), tree[tree.size() - 2].symbols.begin(), tree[tree.size() - 2].symbols.end());
        haffman_tree.symbols.insert(haffman_tree.symbols.end(), tree[tree.size() - 1].symbols.begin(), tree[tree.size() - 1].symbols.end());
        haffman_tree.freq = tree[tree.size() - 2].freq + tree[tree.size() - 1].freq;
        for (int i = 0; i < haffman_tree.symbols.size(); ++i) {
            haffman_tree.symbols[i].freq += 1;
        }
        tree.pop_back();
        tree[tree.size() - 1] = haffman_tree;
    }
    int sum = 0;
    std::vector<Symbol> sizes = tree[0].symbols;
    std::sort(alphabet.begin(), alphabet.end(), compare_symbols);
    std::sort(sizes.begin(), sizes.end(), compare_symbols);
    for (int i = 0; i < alphabet.size(); ++i) {
        sum += sizes[i].freq * alphabet[i].freq;
    }
    std::cout << sum;

    return 0;
}
