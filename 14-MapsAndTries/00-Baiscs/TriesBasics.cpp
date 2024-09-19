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

// 🔄 Algorithm for inserting a word into the Trie:
// 1️⃣ Base Case: If the word is empty, mark the current node as terminal.
// 2️⃣ Get the first character of the word and calculate its index.
// 3️⃣ If the child node corresponding to that character exists, move to it.
// 4️⃣ If it does not exist, create a new node and link it.
// 5️⃣ Recursively insert the remaining part of the word.
void insertWord(TrieNode* root, const string& word) {
    if (word.empty()) { // Base case: End of word, mark as terminal
        root->isTerminal = true;
        return;
    }

    char firstChar = word[0]; // First character of the word
    int index = firstChar - 'a'; // Calculate index for child

    // If child node doesn't exist, create it
    if (root->children[index] == NULL) {
        root->children[index] = new TrieNode(firstChar);
    }

    // Recursively insert the remaining word
    insertWord(root->children[index], word.substr(1));
}

// 🔍 Function to search for a word in the Trie:
// 1️⃣ Traverse through the Trie for each character of the word.
// 2️⃣ If at any point the required character is missing, return false.
// 3️⃣ If the word is completely traversed, check if the last node is terminal.
bool searchWord(TrieNode* root, const string& word) {
    if (word.empty()) { // Base case: End of word, check if terminal
        return root->isTerminal;
    }

    char firstChar = word[0];
    int index = firstChar - 'a';

    // If child node doesn't exist, word is not present
    if (root->children[index] == NULL) {
        return false;
    }

    // Recursively search the rest of the word
    return searchWord(root->children[index], word.substr(1));
}

// 🗑️ Function to delete a word from the Trie:
// 1️⃣ Traverse through the Trie for each character.
// 2️⃣ When the word ends, mark the last node as non-terminal.
void deleteWord(TrieNode* root, const string& word) {
    if (word.empty()) { // Base case: End of word, mark as non-terminal
        root->isTerminal = false;
        return;
    }

    char firstChar = word[0];
    int index = firstChar - 'a';

    // If the child exists, recursively delete the remaining part of the word
    if (root->children[index] != NULL) {
        deleteWord(root->children[index], word.substr(1));
    }
}

// 🗑️ Function to free the entire Trie
void deleteTrie(TrieNode* root) {
    delete root; // Destructor will handle child deletion
}

// 🏁 Main function to test Trie insertion, search, and deletion
int main() {
    TrieNode* root = new TrieNode('-'); // Create the root of the Trie

    // Insert example words into the Trie
    insertWord(root, "hello");
    insertWord(root, "world");
    insertWord(root, "bassu");
    insertWord(root, "sham");

    // Search for words in the Trie and display results
    cout << (searchWord(root, "hello") ? "Found" : "Not Found") << endl; // Should print "Found"
    cout << (searchWord(root, "world") ? "Found" : "Not Found") << endl; // Should print "Found"
    cout << (searchWord(root, "test") ? "Found" : "Not Found") << endl;  // Should print "Not Found"

    // Delete a word and search again
    deleteWord(root, "hello");
    cout << (searchWord(root, "hello") ? "Found" : "Not Found") << endl; // Should print "Not Found"

    // Clean up allocated memory for the Trie
    deleteTrie(root);

    return 0;
}

/*
⏳ Time Complexity:
- Insertion: O(m), where m is the length of the word.
- Search: O(m), where m is the length of the word.
- Deletion: O(m), where m is the length of the word.

💾 Space Complexity:
- O(m * n), where m is the length of the word and n is the number of words.

📊 Example Output:
- Found
- Found
- Not Found
- Not Found
*/
