#include <iostream>
#include <string>
#include <cassert>
#include <set>
#include <unordered_map>
#include "HashTable.h"
#include "Set.h"

using namespace std;

int main() {
    Set<string> hashTable;

    unordered_map<string, bool> map;


    hashTable.add("some1");
    hashTable.add("some2");
    hashTable.add("some3");
    hashTable.add("some4");
    hashTable.add("some5");
    hashTable.add("some6");
    hashTable.add("some7");
    hashTable.add("some8");
    hashTable.add("some9");

    cout << (hashTable.has("some1") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some2") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some3") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some4") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some5") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some6") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some7") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some8") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some9") ? "OK" : "FAIL") << endl;
    cout << (hashTable.has("some0") ? "OK" : "FAIL") << endl;


    char command = 0;
    string key;
    while (std::cin >> command >> key) {
        switch (command) {
            case '?':
                std::cout << (hashTable.has(key) ? "OK" : "FAIL") << std::endl;
                break;
            case '+':
                if (!hashTable.has(key)) {
                    hashTable.add(key);
                    std::cout << "OK" << std::endl;

                } else {
                    std::cout << "FAIL" << std::endl;
                }
                break;
            case '-':
                if (hashTable.has(key)) {
                    hashTable.remove(key);
                    std::cout << "OK" << std::endl;

                } else {
                    std::cout << "FAIL" << std::endl;
                }
                break;
            default:
                assert(false);
        }
    }

    return 0;
}