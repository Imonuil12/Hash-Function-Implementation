#include <iostream>
#include <string>
#include "hash.h"

using namespace std;

int hash_function(string text) {
    // Simple hash function: sum of ASCII values of characters modulo table size
    int hash_value = 0;
    for (char c : text) {
        hash_value += static_cast<int>(c);
    }
    return hash_value;  // Modulus will be applied at the time of insertion in hash table
}
