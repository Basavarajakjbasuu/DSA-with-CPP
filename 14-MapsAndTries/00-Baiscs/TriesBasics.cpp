#include <iostream>
using namespace std;

// 🚧 Definition for a Trie node.
class TrieNode {
public:
    char character; // Character value of the node
    TrieNode* children[26]; // Array of pointers for children (for each letter a-z)
    bool isTerminal; // Indicates if the node represents the end of a word

    // Constructor to initialize a TrieNode
    TrieNode(char val) {
        character = val;
        for (int i = 0; i < 26; i++) {
            children[i] = NULL; // Initialize all children to NULL
        }
        isTerminal = false; // Initialize as not terminal
    }

    // Destructor to free memory for child nodes
    ~TrieNode() {
        for (int i = 0; i < 26; i++) {
            delete children[i]; // Recursively delete child nodes
        }
    }
};

// Algorithm for inserting a word into the Trie:
// 1️⃣ If the word is empty, mark the current node as terminal.
// 2️⃣ Get the first character of the word and calculate its index.
// 3️⃣ If the child node corresponding to that character exists, move to it.
// 4️⃣ If it does not exist, create a new node and link it.
// 5️⃣ Recursively insert the remaining part of the word.
void insertWord(TrieNode* root, const string& word) {
    // 🛑 Base case: If the word is empty, mark the current node as terminal
    if (word.empty()) {
        root->isTerminal = true;
        return;
    }

    // Get the first character and its corresponding index
    char firstChar = word[0];
    int indexOfFirstChar = firstChar - 'a'; // Calculate index (0-25)
    TrieNode* child;

    // Check if the child node exists
    if (root->children[indexOfFirstChar] != NULL) {
        // Child is present
        child = root->children[indexOfFirstChar];
    } else {
        // Child is absent; create a new node
        child = new TrieNode(firstChar);
        root->children[indexOfFirstChar] = child; // Link the new node
    }

    // Recursively insert the remaining part of the word
    insertWord(child, word.substr(1));
}

// Function to search for a word in the Trie
bool searchWord(TrieNode* root, const string& word) {
    // 🛑 Base case: If the word is empty, return if current node is terminal
    if (word.empty()) {
        return root->isTerminal;
    }

    // Get the first character and its corresponding index
    char firstChar = word[0];
    int indexOfFirstChar = firstChar - 'a'; // Calculate index (0-25)
    TrieNode* child;

    // Searching
    if (root->children[indexOfFirstChar] != NULL) {
        // Child is present
        child = root->children[indexOfFirstChar];
    } else {
        // Child is absent; word not found
        return false;
    }

    // Recursively search for the remaining part of the word
    return searchWord(child, word.substr(1));
}

int main() {
    // 🏁 Main function to test Trie insertion and search
    TrieNode* root = new TrieNode('-'); // Create the root of the Trie

    // Example words to insert into the Trie
    insertWord(root, "hello");
    insertWord(root, "world");

    // Searching for words in the Trie and displaying results
    cout << (searchWord(root, "hello") ? "Found" : "Not Found") << endl; // Should print "Found"
    cout << (searchWord(root, "world") ? "Found" : "Not Found") << endl; // Should print "Found"
    cout << (searchWord(root, "test") ? "Found" : "Not Found") << endl; // Should print "Not Found"

    delete root; // Clean up allocated memory for the Trie
    return 0;
}

/*
⏳ Time Complexity:
- O(m) for inserting a word of length m, since we iterate over each character.

💾 Space Complexity:
- O(m) for storing the word, plus O(n) for the Trie nodes created, where n is the number of unique characters in the Trie.

📊 Example Output:
- Found
- Found
- Not Found
*/
