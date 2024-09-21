#include <iostream>
#include <vector>
#include <queue>
#include <string>
#include <algorithm>

#define ALPHABETS 26

using namespace std;

class TrieNode {
public:
    TrieNode *childNodes[ALPHABETS];
    bool isWordEnd;
    int frequency;

    TrieNode() {
        isWordEnd = false;
        frequency = 0;
        for (int i = 0; i < ALPHABETS; i++) {
            childNodes[i] = nullptr;
        }
    }
};

struct comp {
    bool operator()(const pair<int, string> &a, const pair<int, string> &b) {
        if (a.first == b.first) {
            return a.second > b.second; // Lexicographical order
        }
        return a.first < b.first; // Higher frequency first
    }
};

class Trie {
private:
    TrieNode *root;

public:
    Trie() {
        root = new TrieNode();
    }

    void insert(const string &key) {
        TrieNode *p = root;
        for (char ch : key) {
            int j = ch - 'a'; // Assuming lowercase letters only
            if (!p->childNodes[j]) {
                p->childNodes[j] = new TrieNode();
            }
            p = p->childNodes[j];
        }
        if (!p->isWordEnd) {
            p->isWordEnd = true; // Mark end of the word
        }
        p->frequency++; // Increment frequency
    }

    void traverse(TrieNode* node, string s, priority_queue<pair<int, string>, vector<pair<int, string>>, comp> &pq, int k) {
        if (node->isWordEnd) {
            pq.push({node->frequency, s});
        }

        for (int i = 0; i < ALPHABETS; i++) {
            if (node->childNodes[i]) {
                traverse(node->childNodes[i], s + char(i + 'a'), pq, k);
            }
        }
    }

    void getTopKFrequent(int k, vector<string> &answer) {
        priority_queue<pair<int, string>, vector<pair<int, string>>, comp> pq;
        traverse(root, "", pq, k);

        while (!pq.empty() && k-- > 0) {
            answer.push_back(pq.top().second);
            pq.pop();
        }
    }
};

class Solution {
public:
    vector<string> topKFrequent(vector<string>& words, int k) {
        Trie trie;
        vector<string> answer;

        for (const auto& word : words) {
            trie.insert(word);
        }

        trie.getTopKFrequent(k, answer);
        return answer;
    }
};

int main() {
    Solution solution;
    vector<string> words = {"i", "love", "leetcode", "i", "love", "coding"};
    int k = 2;

    vector<string> result = solution.topKFrequent(words, k);

    // Output the result
    for (const string &word : result) {
        cout << word << " ";
    }
    cout << endl;

    return 0;
}
