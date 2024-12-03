/*
CSE 310 Hash Function DIY Contest
Instructor: Yiran "Lawrence" Luo
Your name(s): Imonuil Suleimanov
Your team alias: N/A
*/

#include <iostream>
#include <iomanip>
#include <string>
#include "hash.h"
using namespace std;

int main() {

    int k = 0;
    int n = 0;
    string texts[500];

    // WARNING: Start of the tokenizer that loads the input from std::cin, DO NOT change this part!
    cin >> k;
    string line;
    getline(cin, line);

    while (getline(cin, line)) {
        texts[n] = line;
        n++;
    }
    // WARNING: End of the tokenizer, DO NOT change this part!

    // Create a hash table with k slots
    HashTable hashTable(k);

    // Insert all tokens into the hash table
    for (int i = 0; i < n; i++) {
        hashTable.insert(texts[i]);
    }

    // Print the required outputs
    hashTable.printFirstFiveSlots();
    hashTable.printSlotLengths();
    hashTable.printStandardDeviation();

    return 0;
}
