#include <iostream>
#include <list>
using namespace std;

const int SIZE = 10; // Size of the hash table

// ---------- LINEAR PROBING ----------
class LinearProbing {
    long hashTable[SIZE];
public:
    LinearProbing() {
        for (int i = 0; i < SIZE; i++) hashTable[i] = -1;
    }

    int hashFunction(long key) {
        return key % SIZE;
    }

    void insert(long key) {
        int index = hashFunction(key);
        while (hashTable[index] != -1) {
            index = (index + 1) % SIZE;
        }
        hashTable[index] = key;
    }

    int search(long key) {
        int index = hashFunction(key);
        int comparisons = 1;
        while (hashTable[index] != key) {
            index = (index + 1) % SIZE;
            comparisons++;
            if (comparisons > SIZE) return -1; // Not found
        }
        return comparisons;
    }

    void display() {
        cout << "\nLinear Probing Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": " << (hashTable[i] == -1 ? -1 : hashTable[i]) << "\n";
        }
    }
};

// ---------- CHAINING ----------
class Chaining {
    list<long> hashTable[SIZE];
public:
    int hashFunction(long key) {
        return key % SIZE;
    }

    void insert(long key) {
        int index = hashFunction(key);
        hashTable[index].push_back(key);
    }

    int search(long key) {
        int index = hashFunction(key);
        int comparisons = 0;
        for (auto it : hashTable[index]) {
            comparisons++;
            if (it == key) return comparisons;
        }
        return -1; // Not found
    }

    void display() {
        cout << "\nChaining Table:\n";
        for (int i = 0; i < SIZE; i++) {
            cout << i << ": ";
            for (auto it : hashTable[i]) {
                cout << it << " -> ";
            }
            cout << "NULL\n";
        }
    }
};

// ---------- MAIN FUNCTION ----------
int main() {
    LinearProbing lp;
    Chaining ch;

    int n;
    cout << "Enter number of clients: ";
    cin >> n;

    long number;
    cout << "Enter telephone numbers:\n";
    for (int i = 0; i < n; i++) {
        cin >> number;
        lp.insert(number);
        ch.insert(number);
    }

    lp.display();
    ch.display();

    cout << "\nSearch a number: ";
    cin >> number;

    int compLP = lp.search(number);
    int compCH = ch.search(number);

    if (compLP != -1)
        cout << "Linear Probing Comparisons: " << compLP << "\n";
    else
        cout << "Number not found in Linear Probing\n";

    if (compCH != -1)
        cout << "Chaining Comparisons: " << compCH << "\n";
    else
        cout << "Number not found in Chaining\n";

    return 0;
}





Start
Initiate hash table
Enter client data
Choose hashing technique
Chaining then compute hash table
Insert data into linked list to handle collision at compute index
Look up client data
transverse linked list to find key
Count number of comparison
Open addressing then compute hash table
X lot empty insert key value
At index match return value
Probe next slot
count no Of comparison
analyse
stop
