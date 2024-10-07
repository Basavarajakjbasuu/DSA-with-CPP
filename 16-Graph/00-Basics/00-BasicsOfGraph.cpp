#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

// ✨ Class to represent a Graph
class Graph {
public:
  // Adjacency list to represent graph connections
    unordered_map<int, list<int>> adjacencyLists;

  // ✨ Function to add edges between nodes
  // Algorithm:
  // 1️⃣ If it's a directed graph, add an edge from `sourceNode` to `destinationNode`.
  // 2️⃣ If it's undirected, add edges in both directions.
  // 3️⃣ After adding, the adjacency list is printed to show the current state.
  void addEdges(int sourceNode, int destinationNode, bool isDirected) {
      if (isDirected == 1) {
          // ➡️ Directed graph: add an edge from source to destination
          adjacencyLists[sourceNode].push_back(destinationNode);
      } else {
          // 🔄 Undirected graph: add edges in both directions
          adjacencyLists[sourceNode].push_back(destinationNode);
          adjacencyLists[destinationNode].push_back(sourceNode);
      }
      cout << "Printing adjacency list after adding edge (" << sourceNode << ", " << destinationNode << ")" << endl;
      printAdjacencyList();
      cout << endl;
  }


    // 🖨️ Function to print the adjacency list
    void printAdjacencyList() {
        for (auto node : adjacencyLists) {
            cout << node.first << " -> { ";
            for (auto neighbor : node.second) {
                cout << neighbor << ", ";
            }
            cout << "}" << endl;
        }
    }
};

// 🏁 Main function for testing the graph implementation
int main() {
    Graph g;

    // 🎯 Adding directed edges to the graph
    g.addEdges(0, 1, 1); // Edge from node 0 to 1 (directed)
    g.addEdges(1, 2, 1); // Edge from node 1 to 2 (directed)
    g.addEdges(1, 3, 1); // Edge from node 1 to 3 (directed)
    g.addEdges(3, 2, 1); // Edge from node 3 to 2 (directed)

    return 0;
}

/*
🔍 Explanation:
- The `Graph` class uses an unordered_map to store adjacency lists, where each key is a node, and the value is a list of its neighbors.
- The `addEdges` function handles both directed and undirected edges based on the `direction` parameter.
- The `printAdjList` function prints the adjacency list, showing the graph structure after each edge addition.

⏳ Time Complexity:
- Adding an edge: O(1)
- Printing the adjacency list: O(V + E), where V is the number of vertices and E is the number of edges.

💾 Space Complexity:
- O(V + E) for storing the adjacency list.

📊 Example Output:
After each edge addition, the adjacency list will be printed:
Printing adjacency list after adding edge (0, 1)
0 -> { 1, }

Printing adjacency list after adding edge (1, 2)
0 -> { 1, }
1 -> { 2, }

Printing adjacency list after adding edge (1, 3)
0 -> { 1, }
1 -> { 2, 3, }

Printing adjacency list after adding edge (3, 2)
0 -> { 1, }
1 -> { 2, 3, }
3 -> { 2, }
*/

