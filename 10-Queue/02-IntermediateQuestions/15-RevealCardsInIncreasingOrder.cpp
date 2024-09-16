#include <iostream>
#include <vector>
#include <queue>
#include <algorithm> // for sort
using namespace std;

class Solution {
public:
    vector<int> deckRevealedIncreasing(vector<int>& deck) {
        // 🔽 Step 1: Sort the deck in increasing order
        sort(deck.begin(), deck.end());
        
        queue<int> indexQueue; // 📝 To keep track of indices
        vector<int> result(deck.size()); // 🏁 To store the final revealed order

        // 📊 Initialize the index queue with all indices
        for (int i = 0; i < result.size(); i++)
            indexQueue.push(i);

        // 🔁 Step 2: Place cards according to the reveal rule
        for (int i = 0; i < deck.size(); i++) {
            // 🎯 Place the next smallest card at the front index
            result[indexQueue.front()] = deck[i];
            indexQueue.pop();

            // 🔄 Move the next index to the back to simulate the reveal
            if (!indexQueue.empty()) {
                int nextIndex = indexQueue.front();
                indexQueue.pop();
                indexQueue.push(nextIndex);
            }
        }

        return result;
    }
};

int main() {
    Solution solution;

    // 🧪 Example test case
    vector<int> deck = {17, 13, 11, 2, 3, 5, 7};
    vector<int> result = solution.deckRevealedIncreasing(deck);

    // 📤 Output the resulting revealed deck
    cout << "Revealed deck order: ";
    for (int card : result) {
        cout << card << " ";
    }
    cout << endl;

    return 0;
}

/*
⏳ Time Complexity:
- Sorting the deck takes O(n log n), and simulating the reveal takes O(n), so the overall time complexity is O(n log n), where n is the number of cards.

💾 Space Complexity:
- The space complexity is O(n), due to the usage of the `queue` and `result` vectors.

output:
  Revealed deck order: 2 13 3 11 5 17 7 
*/
