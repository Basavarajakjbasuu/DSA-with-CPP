#include <iostream>
#include <string>
using namespace std;

#define ALPHABETS 26

// 🚧 Node structure for Trie
class TrieNode {
   public:
    TrieNode *children[ALPHABETS]; // Array for each letter 'a' to 'z'
    bool isWordEnd; // Flag to mark the end of a word

    // Constructor to initialize a Trie node
    TrieNode() {
        isWordEnd = false; // Initially, it's not the end of a word
        for (int i = 0; i < ALPHABETS; i++) {
            children[i] = nullptr; // All children initialized to null
        }
    }
};

// 🚧 Trie Class - Handles insertion, search, and prefix checking
class Trie {
   private:
    TrieNode *root; // Root node of the Trie

   public:
    // Constructor initializes root
    Trie() {
        root = new TrieNode();
    }

    // 🌟 Insert a word into the Trie
    void insert(const string &word) {
        TrieNode *currentNode = root; // Start from the root
        for (int i = 0; i < word.length(); i++) {
            int charIndex = word[i] - 'a'; // Calculate index for the letter

            // If the node for this letter doesn't exist, create it
            if (!currentNode->children[charIndex]) {
                currentNode->children[charIndex] = new TrieNode();
            }

            // Move to the child node for this letter
            currentNode = currentNode->children[charIndex];
        }

        // Mark the last node as the end of the word
        currentNode->isWordEnd = true;
    }

    // 🔎 Search for a word or prefix
    bool search(const string &word, bool isPrefix = false) {
        TrieNode *currentNode = root; // Start from the root

        // Traverse through each letter of the word
        for (int i = 0; i < word.length(); i++) {
            int charIndex = word[i] - 'a'; // Calculate index for the letter

            // If the child for this letter doesn't exist, return false
            if (!currentNode->children[charIndex]) {
                return false;
            }

            // Move to the child node for this letter
            currentNode = currentNode->children[charIndex];
        }

        // If it's not a prefix search, ensure the node is a word end
        if (!isPrefix) {
            return currentNode->isWordEnd;
        }

        // Return true for prefix search
        return true;
    }

    // 🧩 Check if any word starts with the given prefix
    bool startsWith(const string &prefix) {
        return search(prefix, true); // Search in prefix mode
    }
};

// 🏁 Main function to demonstrate Trie operations
int main() {
    Trie trie; // Create Trie object

    // 📝 Insert words into the Trie
    trie.insert("apple");
    trie.insert("app");
    trie.insert("bat");

    // 🔍 Search for words and prefixes
    cout << (trie.search("apple") ? "apple found" : "apple not found") << endl; // Should print "apple found"
    cout << (trie.search("app") ? "app found" : "app not found") << endl; // Should print "app found"
    cout << (trie.startsWith("ap") ? "prefix 'ap' exists" : "prefix 'ap' does not exist") << endl; // Should print "prefix 'ap' exists"
    cout << (trie.search("bat") ? "bat found" : "bat not found") << endl; // Should print "bat found"
    cout << (trie.search("batman") ? "batman found" : "batman not found") << endl; // Should print "batman not found"

    return 0;
}

/*
⏳ Time Complexity:
- Insert: O(m), where m is the length of the word.
- Search: O(m), where m is the length of the word or prefix.

💾 Space Complexity:
- O(ALPHABETS * n), where ALPHABETS = 26 and n is the number of nodes.

📊 Example Output:
- apple found
- app found
- prefix 'ap' exists
- bat found
- batman not found
*/

