#include <iostream>
#include <list>

class HashTable {
private:
    int capacity;
    int* table;
    int* data;
    int size;
    int rangeMin;
    int rangeMax;

    int hashFunction(int key) {
        return key % capacity;
    }

    void rehash() {
        int newCapacity = capacity * 2;
        int* newTable = new int[newCapacity];
        int* newData = new int[newCapacity];

        for (int i = 0; i < newCapacity; i++) {
            newTable[i] = -1;
            newData[i] = -1;
        }

        for (int i = 0; i < capacity; i++) {
            if (table[i] != -1) {
                int newIndex = hashFunction(table[i]);
                while (newTable[newIndex] != -1) {
                    newIndex = (newIndex + 1) % newCapacity; // Linear probing
                }
                newTable[newIndex] = table[i];
                newData[newIndex] = data[i];
            }
        }

        delete[] table;
        delete[] data;
        table = newTable;
        data = newData;
        capacity = newCapacity;
    }

public:
    HashTable(int tableSize, int rangeStart, int rangeEnd)
        : capacity(tableSize), rangeMin(rangeStart), rangeMax(rangeEnd), size(0)
    {
        table = new int[capacity];
        data = new int[capacity];
        for (int i = 0; i < capacity; i++) {
            table[i] = -1;
            data[i] = -1;
        }
    }

    ~HashTable() {
        delete[] table;
        delete[] data;
    }

    bool insert(int key, int value) {
        if (key < rangeMin || key > rangeMax) {
            std::cout << "Key " << key << " is outside the range [" << rangeMin << ", " << rangeMax << "]." << std::endl;
            return false;
        }

        if (size >= 0.7 * capacity) {
            rehash();
        }

        int index = hashFunction(key);
        while (table[index] != -1) {
            if (table[index] == key) {
                std::cout << "Key " << key << " already exists in the table." << std::endl;
                return false;
            }
            index = (index + 1) % capacity; // Linear probing
        }

        table[index] = key;
        data[index] = value;
        size++;
        std::cout << "Key " << key << " inserted into the table." << std::endl;
        return true;
    }

    bool search(int key) {
        int index = hashFunction(key);
        int probes = 0;

        while (table[index] != -1) {
            if (table[index] == key) {
                std::cout << "Key " << key << " found with value " << data[index] << "." << std::endl;
                return true;
            }
            index = (index + 1) % capacity; // Linear probing
            probes++;
            if (probes >= capacity) {
                break;
            }
        }

        std::cout << "Key " << key << " not found in the table." << std::endl;
        return false;
    }
};

int main() {
    HashTable table(5, 0, 10);

    table.insert(2, 123);
    table.insert(12, 456);
    table.insert(5, 789);
    table.insert(9, 321);
    table.insert(7, 654);

    table.search(5);
    table.search(12);
    table.search(8);

    return 0;
}
