#include <iostream>
#include <fstream>
#include <vector>
#include <list>
#include <algorithm>

class HashTable {
private:
    static const int TABLE_SIZE = 101;
    std::vector<std::list<std::string>> table;

    // Hash function to calculate index
    int hashFunction(const std::string& word) const {
        int sum = 0;
        for (char ch : word) {
            sum += static_cast<int>(ch);
        }
        return sum % TABLE_SIZE;
    }

public:
    // Constructor initializes the hash table
    HashTable() : table(TABLE_SIZE) {}

    // Insert a word into the hash table
    void insertWord(const std::string& word) {
        int index = hashFunction(word);
        table[index].push_back(word);
    }

    // Check if a word exists in the hash table
    bool lookupWord(const std::string& word) const {
        int index = hashFunction(word);
        const auto& bucket = table[index];
        return std::find(bucket.begin(), bucket.end(), word) != bucket.end();
    }
};

int main() {
    // Read words from the dictionary file and insert into hash table
    HashTable hashTable;
    std::ifstream dictionaryFile("dictionary.txt");
    std::string word;

    if (dictionaryFile.is_open()) {
        while (dictionaryFile >> word) {
            hashTable.insertWord(word);
        }
        dictionaryFile.close();
    } else {
        std::cerr << "Unable to open dictionary file." << std::endl;
        return 1;
    }

    // Prompt user for input and check if each word is spelled correctly
    std::cout << "Enter words to check spelling (type 'exit' to quit):" << std::endl;

    while (true) {
        std::cout << "Enter word: ";
        std::cin >> word;

        if (word == "exit") {
            break;
        }

        if (hashTable.lookupWord(word)) {
            std::cout << "Correctly spelled." << std::endl;
        } else {
            std::cout << "Incorrectly spelled." << std::endl;
        }
    }

    return 0;
}