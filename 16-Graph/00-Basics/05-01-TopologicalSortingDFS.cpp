#include <iostream>
#include <unordered_map>
#include <list>
#include <map>
#include <stack>
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

    // 🔄 Function to perform DFS and topological sorting
    // Algorithm:
    // 1️⃣ Mark the current node as visited.
    // 2️⃣ Recursively visit all its neighbors that are not visited.
    // 3️⃣ Once done with all neighbors, push the current node onto the stack.
    void topologicalSortingDFS(int src, map<int, bool>& isVisited, stack<int>& topoStack) {
        isVisited[src] = true;  // Mark the node as visited

        // 🔁 Visit all the neighbors of the current node
        for (auto neighbor : adjacencyLists[src]) {
            if (!isVisited[neighbor]) {
                // 🔄 Recursive call to visit the neighbor
                topologicalSortingDFS(neighbor, isVisited, topoStack);
            }
        }

        // 🗂 Push the current node onto the stack after visiting its neighbors
        topoStack.push(src);
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
    g.addEdges(4, 6, 1);  
    g.addEdges(5, 6, 1);  
    g.addEdges(6, 7, 1);  

    // 🖨️ Print the adjacency list of the graph
    g.printAdjacencyList();

    // 🌟 Perform Topological Sorting using DFS
    int numNodes = 8;  // Total number of nodes in the graph
    map<int, bool> isVisited;  // Keeps track of visited nodes
    stack<int> topoStack;      // Stack to store the topological order

    // 🔄 Call DFS on each node if it is not visited
    for (int i = 0; i < numNodes; i++) {
        if (!isVisited[i]) {
            g.topologicalSortingDFS(i, isVisited, topoStack);
        }
    }

    // 🖨️ Print the topological order by popping from the stack
    cout << "Topological Sorting: ";
    while (!topoStack.empty()) {
        cout << topoStack.top() << " ";
        topoStack.pop();
    }
    cout << endl;

    return 0;
}

/*
📋 Sample Output:

0 -> { 1, }
1 -> { 2, }
2 -> { 3, }
3 -> { 4, 5, }
4 -> { 6, }
5 -> { 6, }
6 -> { 7, }
7 -> { }
Topological Sorting: 0 1 2 3 5 4 6 7 

Explanation:
1️⃣ The graph has nodes 0 to 7. The topological order ensures that for any directed edge u -> v, u comes before v in the order.
2️⃣ In the topological order printed above, node 0 has no incoming edges, and it starts the sorting. Each subsequent node follows this order constraint.

⏳ Time Complexity (TC):
- O(V + E), where V is the number of vertices and E is the number of edges.
- Each node and edge are visited exactly once.

🗂 Space Complexity (SC):
- O(V), where V is the number of vertices. The space is used for the visited map and stack.
*/

