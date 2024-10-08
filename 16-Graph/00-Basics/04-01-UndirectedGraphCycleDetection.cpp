#include <iostream>
#include <list>
#include <queue>
#include <unordered_map>
#include <vector>
using namespace std;

template <typename T>
// ✨ Class to represent an Unweighted Graph
class Graph {
public:
    // Adjacency list representation of the graph
    unordered_map<T, list<T>> adjLists;

    // ✨ Function to add edges in the graph
    // Algorithm:
    // 1️⃣ Add the edge for directed/undirected graphs.
    // 2️⃣ If directed, add only one edge. If undirected, add edges in both directions.
    void addEdgeToGraph(T sourceNode, T destinationNode, bool isDirected) {
        if (isDirected == 1) {
            // ➡️ Directed graph: add an edge from source to destination
            adjLists[sourceNode].push_back(destinationNode);
        } else {
            // 🔄 Undirected graph: add edges in both directions
            adjLists[sourceNode].push_back(destinationNode);
            adjLists[destinationNode].push_back(sourceNode);
        }
    }

    // 🖨️ Function to print the adjacency list
    void printGraph() {
        // Iterate through each node and its neighbors
        for (auto list : adjLists) {
            cout << list.first << ": {";
            for (auto neighbor : list.second) {
                cout << neighbor << ", ";
            }
            cout << "}" << endl;
        }
    }

    // 🔄 Function to detect a cycle in an undirected graph using DFS
    // Algorithm:
    // 1️⃣ Traverse each node and mark it as visited.
    // 2️⃣ Recursively visit its neighbors, skipping the parent node.
    // 3️⃣ If a visited neighbor is not the parent, a cycle is detected.
    bool detectCycleDFS(T src, unordered_map<T, bool>& isVisited, T parent) {
        isVisited[src] = true;  // Mark current node as visited
        
        for (auto neighbor : adjLists[src]) {
            if (neighbor == parent) {
                continue;  // Skip the parent node
            }
            
            if (!isVisited[neighbor]) {
                // 🔁 Recursively visit the neighbor
                bool ans = detectCycleDFS(neighbor, isVisited, src);
                if (ans == true) {
                    return true;  // Cycle detected
                }
            } 
            // If the neighbor is visited and not the parent, we have a cycle
            else if (isVisited[neighbor] == true && neighbor != parent) {
                return true;
            }
        }
    
      return false;  // No cycle detected
  }

  // 🔄 Function to detect a cycle using BFS
  // Algorithm:
  // 1️⃣ Use a queue for BFS traversal and maintain a parent map to track the parent of each node.
  // 2️⃣ For each node, if a visited neighbor is not its parent, a cycle is detected.
  bool isCycleDetected(T src) {
      queue<T> q;
      unordered_map<T, bool> isVisited;
      unordered_map<T, T> parent;

      // Start BFS from the source node
      q.push(src);
      isVisited[src] = true;
      parent[src] = -1;  // Initialize the parent of the source node

      while (!q.empty()) {
          T frontNode = q.front();
          q.pop();

          // Explore all the neighbors of the current node
          for (auto neighbor : adjLists[frontNode]) {
              // If the neighbor is unvisited, mark it as visited and set its parent
              if (!isVisited[neighbor]) {
                  q.push(neighbor);
                  isVisited[neighbor] = true;
                  parent[neighbor] = frontNode;
              }
              // If the neighbor is visited and not the parent, a cycle is found
              else if (isVisited[neighbor] == true && neighbor != parent[frontNode]) {
                  return true;  // Cycle detected
              }
          }
      }

      return false;  // No cycle detected
  }
};

// 🏁 Main function to test the cycle detection using both DFS and BFS
int main() {
    // 🔄 Create an undirected graph and add edges
    Graph<char> grp;

    grp.addEdgeToGraph('a','b', 0);  // Edge a -> b
    grp.addEdgeToGraph('b','c', 0);  // Edge b -> c
    grp.addEdgeToGraph('b','d', 0);  // Edge b -> d
    grp.addEdgeToGraph('d','a', 0);  // Edge d -> a (forms a cycle)

    // Detect cycle using DFS
    unordered_map<char, bool> isVisited;
    bool isCyclic = grp.detectCycleDFS('a', isVisited, -1);

    if (isCyclic) {
        cout << "Graph is cyclic (DFS)\n";  // Output: Graph is cyclic
    } else {
        cout << "Graph is Acyclic (DFS)\n";
    }

    // 🔄 Create another undirected graph without a cycle
    Graph<char> grp1;
    grp1.addEdgeToGraph('a','b', 0);  // Edge a -> b
    grp1.addEdgeToGraph('b','c', 0);  // Edge b -> c
    grp1.addEdgeToGraph('b','d', 0);  // Edge b -> d
    grp1.addEdgeToGraph('e','a', 0);  // Edge e -> a (no cycle)

    // Detect cycle using BFS
    isCyclic = grp1.isCycleDetected('a');

    if (isCyclic) {
        cout << "Graph is cyclic (BFS)\n";  // Output: Graph is cyclic
    } else {
        cout << "Graph is Acyclic (BFS)\n";  // Output: Graph is Acyclic
    }

    return 0;
}

/*
📋 Sample Output:

Graph is cyclic (DFS)
Graph is Acyclic (BFS)

Explanation:
1️⃣ The first graph contains a cycle: 'a' -> 'b' -> 'd' -> 'a', so the output is "Graph is cyclic (DFS)".
2️⃣ The second graph has no cycle, so the output is "Graph is Acyclic (BFS)".

⏳ Time Complexity (TC):
- In the worst case, we visit all vertices and edges in the graph.
- For a graph with V vertices and E edges, the time complexity is O(V + E) for both DFS and BFS.

🗂 Space Complexity (SC):
- The space complexity is O(V) for storing the visited map, parent map, and the stack/queue used in DFS/BFS traversal.
*/
