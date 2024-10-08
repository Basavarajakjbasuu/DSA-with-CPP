#include <iostream>
#include <unordered_map>
#include <vector>
using namespace std;

class Solution {
public:
    // 🔄 Function to detect cycle in a directed graph using DFS
    // Algorithm:
    // 1️⃣ Each node is visited exactly once.
    // 2️⃣ Use two maps: `isVisited` to track whether a node is visited, 
    //    and `dfsStack` to keep track of nodes in the current DFS stack.
    // 3️⃣ If a back edge is found (a node in `dfsStack` is revisited), a cycle is detected.
    // 4️⃣ Return `true` if a cycle is detected; otherwise, return `false`.

    bool detectCycleDFS(int src, unordered_map<int, bool>& isVisited, unordered_map<int, bool>& dfsStack, vector<int> adj[]) {
        isVisited[src] = true;  // Mark the current node as visited
        dfsStack[src] = true;   // Mark the node in the current DFS stack

        // 🔁 Traverse all neighbors of the current node
        for (auto neighbor : adj[src]) {
            // If the neighbor is not visited, recursively visit the neighbor
            if (!isVisited[neighbor]) {
                bool cycleDetected = detectCycleDFS(neighbor, isVisited, dfsStack, adj);
                if (cycleDetected) {
                    return true;  // Cycle detected
                }
            }
            // If the neighbor is already visited and is part of the DFS stack, a cycle is found
            if (isVisited[neighbor] == true && dfsStack[neighbor] == true) {
                return true;
            }
        }

        dfsStack[src] = false;  // Unmark the current node from the DFS stack before returning
        return false;  // No cycle detected in this DFS path
    }

    // ✨ Main function to check if the directed graph contains a cycle
    bool isCyclic(int V, vector<int> adj[]) {
        unordered_map<int, bool> isVisited;  // Tracks if a node is visited
        unordered_map<int, bool> dfsStack;   // Tracks nodes in the current DFS recursion stack

        // 🔄 Traverse all nodes of the graph
        for (int node = 0; node < V; node++) {
            if (!isVisited[node]) {
                // Start DFS from the unvisited node
                if (detectCycleDFS(node, isVisited, dfsStack, adj)) {
                    return true;  // Cycle detected in the graph
                }
            }
        }

        return false;  // No cycle detected in the entire graph
    }
};

// 🏁 Main function to test the cycle detection in a directed graph
int main() {
    // 🖼️ Example: Create a directed graph using adjacency list representation
    int vertices = 4;  // Number of vertices
    vector<int> adj[vertices];  // Adjacency list of size 4

    // 🔗 Add directed edges to the graph
    adj[0].push_back(1);  // 0 -> 1
    adj[1].push_back(2);  // 1 -> 2
    adj[2].push_back(3);  // 2 -> 3
    adj[3].push_back(1);  // 3 -> 1 (creates a cycle)

    // 🔍 Create a Solution object and check for cycle
    Solution solution;
    bool isCyclic = solution.isCyclic(vertices, adj);

    // 🖨️ Print the result
    if (isCyclic) {
        cout << "Graph contains a cycle\n";
    } else {
        cout << "Graph doesn't contain a cycle\n";
    }

    return 0;
}

/*
📋 Sample Output:

Graph contains a cycle

Explanation:
1️⃣ The graph contains a cycle: 1 -> 2 -> 3 -> 1, so the output is "Graph contains a cycle".

⏳ Time Complexity (TC):
- Each node and its neighbors are visited exactly once.
- For `V` vertices and `E` edges, the time complexity is O(V + E).

🗂 Space Complexity (SC):
- Space complexity is O(V) for the `isVisited` and `dfsStack` maps, where V is the number of vertices.
*/

/*
✨ Commit Message: 

*/
