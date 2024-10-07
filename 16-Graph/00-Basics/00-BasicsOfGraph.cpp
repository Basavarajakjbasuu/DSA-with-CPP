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
        // 🖨️ Print the adjacency list after every edge addition
        cout << "Printing adjacency list after adding edge (" << sourceNode << ", " << destinationNode << ")" << endl;
        printAdjacencyList(); // Call to print the adjacency list
        cout << endl;
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
};

// ✨ Class to represent a Weighted Graph
class WeightedGraph {
public:
    // Adjacency list with weights represented as a pair (neighbor, weight)
    unordered_map<int, list<pair<int, int>>> adjLists;

    // ✨ Function to add edges with weights in a weighted graph
    // Algorithm:
    // 1️⃣ Add the edge with its weight for directed/undirected graphs.
    // 2️⃣ If directed, add only one edge. If undirected, add edges in both directions.
    void addEdgeToWeightedGraph(int sourceNode, int destinationNode, int weight, bool isDirected) {
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
            for (pair<int, int> p : list.second) {
                cout << "{" << p.first << "," << p.second << "}, ";
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

    // 🎯 Weighted Graph example
    WeightedGraph wg;

    // 🎯 Adding directed edges with weights to the weighted graph
    wg.addEdgeToWeightedGraph(0, 1, 5, 1); // Edge 0 -> 1 with weight 5
    wg.addEdgeToWeightedGraph(1, 2, 10, 1); // Edge 1 -> 2 with weight 10
    wg.addEdgeToWeightedGraph(1, 3, 15, 1); // Edge 1 -> 3 with weight 15
    wg.addEdgeToWeightedGraph(3, 1, 17, 1); // Edge 3 -> 1 with weight 17

    return 0;
}

/*
🔍 Explanation:
- The `Graph` class uses an unordered_map to store adjacency lists, where each key is a node, and the value is a list of its neighbors.
- The `addEdges` function handles both directed and undirected edges based on the `isDirected` parameter.
- The `WeightedGraph` class stores edges as pairs of nodes with weights, with similar logic to the `Graph` class.
- The `printAdjacencyList` and `printGraph` functions print the adjacency lists for both graph types.

⏳ Time Complexity:
- Adding an edge: O(1)
- Printing the adjacency list: O(V + E), where V is the number of vertices and E is the number of edges.

💾 Space Complexity:
- O(V + E) for storing the adjacency list.

📊 Example Output:
### For Normal Graph:
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

Printing weighted adjacency list after adding edge (0, 1) with weight 5
0: {{1, 5}, }

Printing weighted adjacency list after adding edge (1, 2) with weight 10
0: {{1, 5}, }
1: {{2, 10}, }

Printing weighted adjacency list after adding edge (1, 3) with weight 15
0: {{1, 5}, }
1: {{2, 10}, {3, 15}, }

Printing weighted adjacency list after adding edge (3, 1) with weight 17
0: {{1, 5}, }
1: {{2, 10}, {3, 15}, }
3: {{1, 17}, }

- The weighted graph shows edges between nodes along with their respective weights.
*/
