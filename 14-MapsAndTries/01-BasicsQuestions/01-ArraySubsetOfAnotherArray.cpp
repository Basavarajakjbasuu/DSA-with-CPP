#include <iostream>
#include <unordered_map>
using namespace std;

// 🔄 Algorithm to check if array a2[] is a subset of array a1[]:
// 1️⃣ Traverse through array a1[] and count occurrences of each element using a hashmap.
// 2️⃣ Traverse through array a2[]:
//     - For each element, check if it exists in the hashmap (from array a1[]).
//     - If it exists, decrement its count in the hashmap. If the count becomes zero, remove it.
//     - If it doesn’t exist or the count is zero, return "No".
// 3️⃣ If all elements of a2[] are found in a1[], return "Yes".

string isSubset(int a1[], int a2[], int n, int m) {
    unordered_map<int, int> elementCountMap;
    string answer = "Yes";  // Default answer is "Yes" unless proven otherwise.

    // 📊 Step 1: Count the occurrences of each element in array a1[].
    for (int i = 0; i < n; i++) {
        elementCountMap[a1[i]]++;
    }

    // 🧐 Step 2: Check if each element of a2[] exists in the hashmap and can be matched.
    for (int i = 0; i < m; i++) {
        if (elementCountMap.find(a2[i]) == elementCountMap.end() || elementCountMap[a2[i]] == 0) {
            answer = "No";  // ❌ Element not found or already used up.
            break;
        } else {
            elementCountMap[a2[i]]--;  // ✅ Element found, decrement its count.
        }
    }

    return answer;  // Return the result.
}

int main() {
    int a1[] = {1, 2, 3, 4, 5, 6};
    int a2[] = {2, 4, 6};

    int n = sizeof(a1) / sizeof(a1[0]);
    int m = sizeof(a2) / sizeof(a2[0]);

    // Test case: Is a2[] a subset of a1[]?
    cout << "Is a2[] a subset of a1[]? " << isSubset(a1, a2, n, m) << endl;

    return 0;
}

/*
⏳ Time Complexity:
- O(n + m), where n is the size of array a1[] and m is the size of array a2[].
  - O(n) to build the hashmap.
  - O(m) to check the elements of a2[].

💾 Space Complexity:
- O(n), due to the unordered_map storing the count of elements in a1[].

📊 Example Output:
Is a2[] a subset of a1[]? Yes
*/
