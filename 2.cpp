#include <iostream>
#include <cstring>
using namespace std;

class HashTable {
    struct Entry {
        long key;
        char name[10];
    };

    Entry table[10];

public:
    HashTable() {
        for (int i = 0; i < 10; i++) {
            table[i].key = -1;
            strcpy(table[i].name, "NULL");
        }
    }

    void insert() {
        long key;
        char name[10];
        char choice;
        do {
            cout << "Enter telephone number: ";
            cin >> key;
            cout << "Enter client name: ";
            cin >> name;

            int index = key % 10;
            int original = index;
            bool placed = false;

            for (int i = 0; i < 10; i++) {
                int pos = (index + i) % 10;
                if (table[pos].key == -1) {
                    table[pos].key = key;
                    strcpy(table[pos].name, name);
                    placed = true;
                    break;
                }
            }

            if (!placed) {
                cout << "Hash table is full!\n";
            }

            cout << "Insert more? (y/n): ";
            cin >> choice;
        } while (choice == 'y' || choice == 'Y');
    }

    void display() {
        cout << "\nIndex\tKey\tName\n";
        for (int i = 0; i < 10; i++) {
            cout << i << "\t" << table[i].key << "\t" << table[i].name << "\n";
        }
    }

    int find(long key) {
        for (int i = 0; i < 10; i++) {
            if (table[i].key == key) {
                cout << "Found at index " << i << " with name " << table[i].name << "\n";
                return i;
            }
        }
        return -1;
    }

    void remove(long key) {
        int index = find(key);
        if (index != -1) {
            table[index].key = -1;
            strcpy(table[index].name, "NULL");
            cout << "Key deleted.\n";
        } else {
            cout << "Key not found.\n";
        }
    }
};

int main() {
    HashTable ht;
    int choice;
    long key;
    char cont;

    do {
        cout << "\n--- Telephone Directory ---\n";
        cout << "1. Insert\n2. Display\n3. Find\n4. Delete\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: ht.insert(); break;
            case 2: ht.display(); break;
            case 3:
                cout << "Enter key to search: ";
                cin >> key;
                if (ht.find(key) == -1)
                    cout << "Key not found.\n";
                break;
            case 4:
                cout << "Enter key to delete: ";
                cin >> key;
                ht.remove(key);
                break;
            case 5: return 0;
            default: cout << "Invalid choice.\n";
        }

        cout << "Continue? (y/n): ";
        cin >> cont;
    } while (cont == 'y' || cont == 'Y');

    return 0;
}



Start

1.Create a structure Entry with:

key (telephone number)

name (client name)

2.Create a hash table of size 10 and initialize all:

key = -1

name = "NULL"

3.Insert Operation:

Input key and name

Compute index = key % 10

Linearly probe (i.e., try next cells) until an empty slot is found

Insert key and name at that position

4.Display Operation:

Print index, key, and name for all 10 entries

5.Find/Search Operation:

Input key to find

Search linearly through table

If found, display index and name

6.Delete Operation:

Input key to delete

If found, reset key = -1, name = "NULL"

Repeat until user chooses to exit

End
