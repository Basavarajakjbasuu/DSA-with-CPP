#include <iostream>
#include <list>
#include <unordered_map>
#include <queue>
using namespace std;

template <typename T>

// ✨ Class to represent a Weighted Graph
class WeightedGraph {
public:
    // Adjacency list with weights represented as a pair (neighbor, weight)
    unordered_map<T, list<pair<T, int>>> adjLists;

    // ✨ Function to add edges with weights in a weighted graph
    // Algorithm:
    // 1️⃣ Add the edge with its weight for directed/undirected graphs.
    // 2️⃣ If directed, add only one edge. If undirected, add edges in both directions.
    void addEdgeToWeightedGraph(T sourceNode, T destinationNode, int weight, bool isDirected) {
        if (isDirected == 1) {
            // ➡️ Directed graph: add an edge with weight from source to destination
            adjLists[sourceNode].push_back(make_pair(destinationNode, weight));
        } else {
            // 🔄 Undirected graph: add weighted edges in both directions
            adjLists[sourceNode].push_back(make_pair(destinationNode, weight));
            adjLists[destinationNode].push_back(make_pair(sourceNode, weight));
        }
    }

    // 🖨️ Function to print the weighted adjacency list
    // Improved for better readability
    void printGraph() {
        cout << "Printing weighted adjacency list:" << endl;
        // Iterate through each node and its neighbors with weights
        for (auto& list : adjLists) {
            cout << list.first << ": {";
            // Print each neighbor and its weight
            for (auto& neighbor : list.second) {
                cout << "{" << neighbor.first << "," << neighbor.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    // 🔄 Function to perform BFS traversal
    // Algorithm:
    // 1️⃣ Use a queue to traverse nodes level by level.
    // 2️⃣ Mark nodes as visited once they're added to the queue.
    // 3️⃣ For each node, explore its neighbors and continue until all nodes are visited.
    void BFSTraversal(T src) {
        // Hash map to track visited nodes
        unordered_map<T, bool> isVisited;

        // Queue to explore nodes in BFS order
        queue<T> q;

        // Start with the source node
        q.push(src);
        isVisited[src] = true; // Mark as visited

        // Process the graph until the queue is empty
        while (!q.empty()) {
            T frontNode = q.front(); // Current node
            cout << frontNode << " "; // Print the node
            q.pop(); // Remove from queue

            // Explore all neighbors of the current node
            for (auto neighbor : adjLists[frontNode]) {
                T neighborData = neighbor.first;

                // If the neighbor hasn't been visited yet, visit it
                if (!isVisited[neighborData]) {
                    q.push(neighborData); // Add to the queue
                    isVisited[neighborData] = true; // Mark as visited
                }
            }
        }
    }

    void BFSTraversalDisconnectedComp(T src, unordered_map<char, bool>& isVisited) {

        // Queue to explore nodes in BFS order
        queue<T> q;

        // Start with the source node
        q.push(src);
        isVisited[src] = true; // Mark as visited

        // Process the graph until the queue is empty
        while (!q.empty()) {
            T frontNode = q.front(); // Current node
            cout << frontNode << " "; // Print the node
            q.pop(); // Remove from queue

            // Explore all neighbors of the current node
            for (auto neighbor : adjLists[frontNode]) {
                T neighborData = neighbor.first;

                // If the neighbor hasn't been visited yet, visit it
                if (!isVisited[neighborData]) {
                    q.push(neighborData); // Add to the queue
                    isVisited[neighborData] = true; // Mark as visited
                }
            }
        }
    }

};

// 🏁 Main function to test the graph implementation
int main() {
    WeightedGraph<char> gph;

    // 🎯 Adding weighted edges (undirected graph)
    gph.addEdgeToWeightedGraph('a', 'b', 5, 0);
    gph.addEdgeToWeightedGraph('a', 'c', 5, 0);
    gph.addEdgeToWeightedGraph('b', 'c', 5, 0);
    gph.addEdgeToWeightedGraph('c', 'd', 5, 0);
    gph.addEdgeToWeightedGraph('c', 'e', 5, 0);
    gph.addEdgeToWeightedGraph('e', 'f', 5, 0);

    // 🖨️ Print the weighted graph
    gph.printGraph();

    // 🔄 Perform BFS traversal starting from node 'a'
    cout << "\nBFS Traversal starting from node 'a': ";
    gph.BFSTraversal('a');

    // Handle disconnected components in graph

    WeightedGraph<char> gph1;

    gph1.addEdgeToWeightedGraph('a', 'b', 5, 0);
    gph1.addEdgeToWeightedGraph('b', 'c', 5, 0);
    gph1.addEdgeToWeightedGraph('e', 'd', 5, 0);
    gph1.addEdgeToWeightedGraph('f', 'f', 5, 0);

    cout << "\n BST for disconnected components in graph \n";
    unordered_map<char, bool> vis;
    for (char node='a'; node<= 'f'; node++) {
      if(!vis[node]) {
        gph1.BFSTraversalDisconnectedComp(node, vis);
      }
    }
    return 0;
}

/*
    ⏳ Time Complexity:
  - **Add edge to weighted graph:** O(1) for each edge insertion.
  - **BFS Traversal:**
    - Visiting each node: O(V), where V is the number of vertices.
    - Visiting all edges: O(E), where E is the number of edges.
    - **Overall TC for BFS:** O(V + E).

  💾 Space Complexity:
  - **Adjacency List Storage:** O(V + E), as it stores all vertices and edges.
  - **BFS Traversal:** O(V) for the queue and visited list.

  🔍 Explanation of Output:
  Printing weighted adjacency list:
  a: {{b,5}, {c,5}, }
  b: {{a,5}, {c,5}, }
  c: {{a,5}, {b,5}, {d,5}, {e,5}, }
  d: {{c,5}, }
  e: {{c,5}, {f,5}, }
  f: {{e,5}, }

  BFS Traversal starting from node 'a': a b c d e f 

  BST for disconnected components in graph a b c d e f

*/