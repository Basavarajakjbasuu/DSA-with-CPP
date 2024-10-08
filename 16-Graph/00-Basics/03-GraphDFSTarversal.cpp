#include <iostream>
#include <list>
#include <unordered_map>
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

        // 🖨️ Print the weighted adjacency list after adding the edge
        cout<< "Printing weighted adjacency list after adding edge (" <<sourceNode<< "," <<destinationNode <<") with weight " <<weight << endl;
        printGraph();
        cout << endl;
    }

    // 🖨️ Function to print the weighted adjacency list
    void printGraph() {
        // Iterate through each node and its neighbors with weights
        for (auto list : adjLists) {

            cout << list.first << ": {";
            // Print each neighbor and its weight
            for (pair<T, int> p : list.second) {
                cout << "{" << p.first << "," << p.second << "}, ";
            }
            cout << "}" << endl;
        }
    }

    // 🔄 Function to perform DFS traversal
    // Algorithm:
    // 1️⃣ Start at the source node, mark it as visited, and print it.
    // 2️⃣ Recursively visit all unvisited neighbors of the current node.
    void DFSTraversal(T src, unordered_map<T, bool>& isVisited) {
        // Mark the current node as visited
        isVisited[src] = true;
        cout << src << " ";  // Print the node

        // Traverse all the neighbors of the current node
        for (auto nbr : adjLists[src]) {
            T nbrData = nbr.first;
            // Visit unvisited neighbors recursively
            if (!isVisited[nbrData]) {
                DFSTraversal(nbrData, isVisited);
            }
        }
    }
};

// 🏁 Main function for testing the graph implementation
int main() {

    WeightedGraph<char> chWtGraph;

    // 🎯 Adding weighted edges (directed graph)
    chWtGraph.addEdgeToWeightedGraph('a','b', 2, 1); // Edge a -> b with weight 2
    chWtGraph.addEdgeToWeightedGraph('b','k', 4, 1); // Edge b -> k with weight 4
    chWtGraph.addEdgeToWeightedGraph('b','d', 8, 1); // Edge b -> d with weight 8
    chWtGraph.addEdgeToWeightedGraph('d','e', 10, 1); // Edge d -> e with weight 10

    // 🧭 DFS traversal
    unordered_map<char, bool> isVisited;
    cout << "DFS Traversal starting from node 'a': ";
    chWtGraph.DFSTraversal('a', isVisited);

    return 0;
}

/*
📋 Sample Output:

Printing weighted adjacency list after adding edge (a,b) with weight 2
a: {{b,2}, }
b: {}
Printing weighted adjacency list after adding edge (b,k) with weight 4
a: {{b,2}, }
b: {{k,4}, }
Printing weighted adjacency list after adding edge (b,d) with weight 8
a: {{b,2}, }
b: {{k,4}, {d,8}, }
Printing weighted adjacency list after adding edge (d,e) with weight 10
a: {{b,2}, }
b: {{k,4}, {d,8}, }
d: {{e,10}, }

DFS Traversal starting from node 'a': a b k d e

Explanation:
1️⃣ The DFS traversal starts from node 'a'.
2️⃣ It moves to node 'b' (neighbor of 'a').
3️⃣ From 'b', it visits 'k' (neighbor of 'b').
4️⃣ After visiting 'k', it returns to 'b' and visits 'd'.
5️⃣ Finally, from 'd', it visits 'e'.

Traversal order: a b k d e

⏳ Time Complexity (TC):
- For DFS, each node and its edges are visited once.
- For a graph with V vertices and E edges, the time complexity is O(V + E).

🗂 Space Complexity (SC):
- The space complexity is O(V) for the recursion stack (in case of DFS) and the visited array.
*/
