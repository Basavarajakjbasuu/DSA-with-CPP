#include <iostream>
#include <vector>
#include <string>
using namespace std;

#define ALPHABETS 26

// 🚧 TrieNode Class
// A node that represents each character in the trie structure. 
// Each node has an array `childNodes` of size 26, corresponding to the 26 lowercase letters,
// and a boolean `isWordEnd` to indicate if the node marks the end of a valid word.
class TrieNode {
   public:
    TrieNode *childNodes[ALPHABETS];
    bool isWordEnd;
    
    // Constructor to initialize TrieNode. All child nodes are initially null and isWordEnd is set to false.
    TrieNode() {
        isWordEnd = false;
        for (int i = 0; i < ALPHABETS; i++) {
            childNodes[i] = nullptr;
        }
    }
};

// 🚧 Trie Class
// The Trie structure to store the root words and perform insertion and search operations.
// This Trie will help in replacing words in the sentence with their root words.
class Trie {
   private:
    TrieNode *root;

   public:
    // Constructor to initialize the root node of the trie.
    Trie() {
        root = new TrieNode();
    }

    // 🔄 insert function
    // This function inserts a word into the trie.
    // It traverses each character in the word, creating new TrieNode objects for characters that do not exist.
    // Time Complexity: O(L), where L is the length of the word being inserted.
    void insert(const string &key) {
        TrieNode *p = root;
        for (int i = 0; i < key.length(); i++) {
            int j = key[i] - 'a';
            if (!p->childNodes[j]) {
                p->childNodes[j] = new TrieNode();
            }
            p = p->childNodes[j];
        }
        p->isWordEnd = true;
    }

    // 🔍 search function
    // This function searches for the shortest root in the trie that matches the prefix of the given word.
    // It returns the root word if found; otherwise, it returns the original word.
    // Time Complexity: O(L), where L is the length of the word being searched.
    string search(const string &key) {
        TrieNode *p = root;
        string prefix;
        
        for (char ch: key) {
            int index = ch -'a';

            if (!p->childNodes[index]) {
                return key;  // Return the original word if no matching prefix is found.
            }

            prefix += ch;
            p = p->childNodes[index];

            if (p->isWordEnd) {
                return prefix;  // Return the root word if a match is found.
            }
        }
        return key;  // Return the original word if no root word is found.
    }
};

// 🔄 replaceWords function
// This function replaces words in the sentence with their root words using the Trie.
// It splits the sentence into words, finds the shortest root for each word, and builds the final sentence.
// Time Complexity: O(D * L + W * M), where D is the number of dictionary words, L is the average length of dictionary words,
// W is the number of words in the sentence, and M is the average length of words in the sentence.
class Solution {
public:
    string replaceWords(vector<string>& dictionary, string sentence) {
        Trie trie;
        string answer;

        // Insert all root words into the trie.
        for (auto root: dictionary) {
            trie.insert(root);
        }

        int start = 0, end = 0;

        // Iterate through each word in the sentence.
        while (end <= sentence.size()) {
            if (sentence[end] == ' ' || end == sentence.size()) {
                // Extract the word from the sentence.
                string word = sentence.substr(start, end - start);
                
                // Search for the root word in the trie.
                string rootWord = trie.search(word);

                // Append the root word (or the original word if no root is found) to the result.
                answer += rootWord;

                if (sentence[end] == ' ') {
                    answer += " ";  // Add space between words.
                }

                // Move to the next word.
                start = end + 1;
            }
            ++end;
        }

        return answer;
    }
};

int main() {
    // Example usage:
    Solution solution;
    
    // Root words in the dictionary
    vector<string> dictionary = {"cat", "bat", "rat"};
    
    // Sentence to replace words with root words
    string sentence = "the cattle was rattled by the battery";
    
    // Replacing words and printing the result
    string result = solution.replaceWords(dictionary, sentence);
    cout << "Modified sentence: " << result << endl; // Expected: "the cat was rat by the bat"
    
    return 0;
}

/*
⏳ Time Complexity:
- Trie Insertion: O(D * L), where D is the number of dictionary words and L is the average length of the words.
- Word Replacement: O(W * M), where W is the number of words in the sentence and M is the average length of the words.

💾 Space Complexity:
- O(D * L) for the Trie structure, where D is the number of dictionary words and L is the average length of the words.

📊 Example:
Input:
dictionary = ["cat", "bat", "rat"]
sentence = "the cattle was rattled by the battery"
Output:
"the cat was rat by the bat"
*/

