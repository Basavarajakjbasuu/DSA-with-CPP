#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <queue>
using namespace std;

class Graph {
public:
    // 🎯 Adjacency list representation of the graph
    unordered_map<int, list<int>> adjacencyLists;

    // ✨ Function to add directed or undirected edges to the graph
    void addEdges(int sourceNode, int destinationNode, bool isDirected) {
        if (isDirected == 1) {
            // ➡️ Directed graph: Add an edge from source to destination
            adjacencyLists[sourceNode].push_back(destinationNode);
        } else {
            // 🔄 Undirected graph: Add edges in both directions
            adjacencyLists[sourceNode].push_back(destinationNode);
            adjacencyLists[destinationNode].push_back(sourceNode);
        }
    }

    // 🖨️ Function to print the adjacency list
    void printAdjacencyList() {
        // Iterate through each node and its neighbors in the adjacency list
        for (auto node : adjacencyLists) {
            cout << node.first << " -> { ";
            // Print all the neighbors of the node
            for (auto neighbor : node.second) {
                cout << neighbor << ", ";
            }
            cout << "}" << endl;
        }
    }

    // 🔄 Function to perform topological sorting using BFS (Kahn's Algorithm)
    // Algorithm:
    // 1️⃣ First, calculate the in-degree of each node.
    // 2️⃣ Push nodes with 0 in-degree to the queue.
    // 3️⃣ While the queue is not empty, process each node:
    //    a. Pop the front node and print it (this node can now be added to the topological order).
    //    b. Reduce the in-degree of all its neighbors.
    //    c. If any neighbor's in-degree becomes 0, push it to the queue.
    void topologicalSortingBFS(int totalNodes) {
        queue<int> q;  // Queue to process nodes with in-degree 0
        map<int, int> inDegrees;  // Map to store in-degree of each node

        // 🧮 Step 1: Calculate in-degree for each node
        for (auto i : adjacencyLists) {
            for (auto neighbor : i.second) {
                inDegrees[neighbor]++;
            }
        }

        // 🧮 Step 2: Push nodes with in-degree 0 to the queue
        for (int node = 0; node < totalNodes; node++) {
            if (inDegrees[node] == 0) {
                q.push(node);
            }
        }

        // 🧮 Step 3: Process the nodes in topological order
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            // 🎯 Output the node as part of the topological order
            cout << frontNode << " ";

            // Reduce the in-degree of all neighbors of the processed node
            for (auto neighbor : adjacencyLists[frontNode]) {
                inDegrees[neighbor]--;

                // If in-degree becomes 0, add the neighbor to the queue
                if (inDegrees[neighbor] == 0) {
                    q.push(neighbor);
                }
            }
        }
    }
};

int main() {
    // 🔄 Create a directed graph and add edges
    Graph g;
    g.addEdges(0, 1, 1);  
    g.addEdges(1, 2, 1);  
    g.addEdges(2, 3, 1);  
    g.addEdges(3, 4, 1);  
    g.addEdges(3, 5, 1);  
    g.addEdges(4, 5, 1);  
    g.addEdges(5, 6, 1);  
    g.addEdges(6, 7, 1);  

    // 🖨️ Print the adjacency list of the graph
    g.printAdjacencyList();

    // 🌟 Perform Topological Sorting using BFS
    int numNodes = 8;  // Total number of nodes in the graph
    cout << "Topological Sorting: ";
    g.topologicalSortingBFS(numNodes);

    cout << endl;
    return 0;
}

/*
📋 Sample Output:

0 -> { 1, }
1 -> { 2, }
2 -> { 3, }
3 -> { 4, 5, }
4 -> { 5, }
5 -> { 6, }
6 -> { 7, }
7 -> { }
Topological Sorting: 0 1 2 3 4 5 6 7 

Explanation:
1️⃣ The graph has nodes 0 to 7. Topological order ensures that every directed edge u -> v implies that u comes before v in the order.
2️⃣ Here, node 0 starts the topological order as it has no incoming edges (in-degree is 0).
3️⃣ The algorithm proceeds to process the next node based on in-degree, ensuring the topological order constraints.

⏳ Time Complexity (TC):
- O(V + E), where V is the number of vertices and E is the number of edges.
- Each node and its adjacent edges are processed exactly once.

🗂 Space Complexity (SC):
- O(V), where V is the number of vertices. The space is used for the in-degree map and the queue.
*/
