#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
    // Create a hashmap (unordered_map)
    unordered_map<string, int> hashmap;

    // Inserting key-value pairs
    hashmap["apple"] = 5;
    hashmap["banana"] = 3;
    hashmap["orange"] = 8;

    // Displaying the elements in the hashmap
    cout << "Hashmap contents:\n";
    for (const auto& pair : hashmap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Lookup operation
    string key = "banana";
    if (hashmap.find(key) != hashmap.end()) {
        cout << key << " found with value: " << hashmap[key] << endl;
    } else {
        cout << key << " not found in the hashmap." << endl;
    }

    // Deleting a key-value pair
    hashmap.erase("apple");
    cout << "After deleting 'apple':\n";
    for (const auto& pair : hashmap) {
        cout << pair.first << ": " << pair.second << endl;
    }

    // Size of the hashmap
    cout << "Size of hashmap: " << hashmap.size() << endl;

    // Clearing the hashmap
    hashmap.clear();
    cout << "Size after clearing: " << hashmap.size() << endl;

    return 0;
}
