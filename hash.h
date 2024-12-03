#ifndef HASH_H
#define HASH_H

#include <iostream>
#include <string>
#include <cmath>

using namespace std;

struct Node {
    string data;
    Node* next;
};

// Declare hash function here so it can be used in both hash.cpp and hash.h
int hash_function(string text);

class HashTable {
private:
    int size;        // Number of slots
    Node** table;    // Array of linked lists (chained)

public:
    HashTable(int size) {
        this->size = size;
        table = new Node*[size];
        for (int i = 0; i < size; i++) {
            table[i] = nullptr;  // Initialize each slot with nullptr
        }
    }

    ~HashTable() {
        for (int i = 0; i < size; i++) {
            Node* current = table[i];
            while (current != nullptr) {
                Node* temp = current;
                current = current->next;
                delete temp;
            }
        }
        delete[] table;
    }

    void insert(string key) {
        int index = hash_function(key) % size;
        Node* newNode = new Node;
        newNode->data = key;
        newNode->next = table[index];
        table[index] = newNode;
    }

    void printFirstFiveSlots() {
        cout << "==== Printing the contents of the first 5 slots ====" << endl;
        for (int i = 0; i < 5 && i < size; i++) {
            cout << "Slot " << i << ": ";
            Node* current = table[i];
            while (current != nullptr) {
                cout << current->data << " ";
                current = current->next;
            }
            cout << endl;
        }
    }

    void printSlotLengths() {
        cout << "==== Printing the slot lengths ====" << endl;
        for (int i = 0; i < size; i++) {
            int length = 0;
            Node* current = table[i];
            while (current != nullptr) {
                length++;
                current = current->next;
            }
            cout << "Slot " << i << ": " << length << endl;
        }
    }

    void printStandardDeviation() {
        double mean = 0;
        double variance = 0;
        int totalSlots = size;

        // Calculate mean slot length
        for (int i = 0; i < size; i++) {
            int length = 0;
            Node* current = table[i];
            while (current != nullptr) {
                length++;
                current = current->next;
            }
            mean += length;
        }
        mean /= totalSlots;

        // Calculate variance
        for (int i = 0; i < size; i++) {
            int length = 0;
            Node* current = table[i];
            while (current != nullptr) {
                length++;
                current = current->next;
            }
            variance += pow(length - mean, 2);
        }
        variance /= totalSlots;

        cout << "==== Printing the standard deviation ====" << endl;
        cout << sqrt(variance) << endl;
    }
};

#endif
