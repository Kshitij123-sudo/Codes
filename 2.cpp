#include <iostream>
#include <list>
#include <string>
using namespace std;

const int SIZE = 10;

class Dictionary {
    list<pair<string, string>> table[SIZE];

    int hashFunction(string key) {
        int hash = 0;
        for (char ch : key) {
            hash = (hash + int(ch)) % SIZE;
        }
        return hash;
    }

public:
    void insert(string key, string value) {
        int index = hashFunction(key);

        // Update if key already exists
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                cout << "Key already exists. Updating value.\n";
                pair.second = value;
                return;
            }
        }

        table[index].push_back({key, value});
    }

    void find(string key) {
        int index = hashFunction(key);
        for (auto &pair : table[index]) {
            if (pair.first == key) {
                cout << "Key: " << key << " | Value: " << pair.second << "\n";
                return;
            }
        }
        cout << "Key not found.\n";
    }

    void deleteKey(string key) {
        int index = hashFunction(key);
        for (auto it = table[index].begin(); it != table[index].end(); ++it) {
            if (it->first == key) {
                table[index].erase(it);
                cout << "Key '" << key << "' deleted.\n";
                return;
            }
        }
        cout << "Key not found. Cannot delete.\n";
    }

    void display() {
        cout << "\nDictionary Hash Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto &pair : table[i]) {
                cout << "[" << pair.first << " : " << pair.second << "] -> ";
            }
            cout << "NULL\n";
        }
    }
};

int main() {
    Dictionary dict;
    int k;
    string key, value;

    cout << "Enter number of key-value pairs: ";
    cin >> k;

    cout << "Enter key-value pairs:\n";
    for (int i = 0; i < k; i++) {
        cin >> key >> value;
        dict.insert(key, value);
    }

    dict.display();

    cout << "\nEnter key to search: ";
    cin >> key;
    dict.find(key);

    cout << "\nEnter key to delete: ";
    cin >> key;
    dict.deleteKey(key);

    dict.display();

    return 0;
}
