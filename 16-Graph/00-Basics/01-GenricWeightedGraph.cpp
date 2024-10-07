#include <iostream>
#include <list>
#include <unordered_map>
using namespace std;

template <typename T>

// ✨ Class to represent a Weighted Graph
class WeightedGraph {
public:
    // Adjacency list with weights represented as a pair (neighbor, weight)
    unordered_map<T, list<pair<T, T>>> adjLists;

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
};

// 🏁 Main function for testing the graph implementation
int main() {

    // 🎯 Weighted Graph example
    WeightedGraph<int> wg;

    // 🎯 Adding directed edges with weights to the weighted graph
    wg.addEdgeToWeightedGraph(0, 1, 5, 1); // Edge 0 -> 1 with weight 5
    wg.addEdgeToWeightedGraph(1, 2, 10, 1); // Edge 1 -> 2 with weight 10
    wg.addEdgeToWeightedGraph(1, 3, 15, 1); // Edge 1 -> 3 with weight 15
    wg.addEdgeToWeightedGraph(3, 1, 17, 1); // Edge 3 -> 1 with weight 17

    WeightedGraph<char> chWtGraph;

    chWtGraph.addEdgeToWeightedGraph('a','b', 2, 1); // Edge a -> b with weight 2
    chWtGraph.addEdgeToWeightedGraph('b','c', 4, 1); // Edge b -> c with weight 4
    chWtGraph.addEdgeToWeightedGraph('b','d', 8, 1); // Edge b -> d with weight 8
    chWtGraph.addEdgeToWeightedGraph('d','a', 10, 1); // Edge b -> a with weight 10

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
 For Integer weighted Graph:

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

OUTPUT: Character weighted Graph:

Printing weighted adjacency list after adding edge (a,b) with weight 2
a: {{b,2}, }

Printing weighted adjacency list after adding edge (b,c) with weight 4
b: {{c,4}, }
a: {{b,2}, }

Printing weighted adjacency list after adding edge (b,d) with weight 8
b: {{c,4}, {d,8}, }
a: {{b,2}, }

Printing weighted adjacency list after adding edge (d,a) with weight 10
d: {{a,10}, }
b: {{c,4}, {d,8}, }
a: {{b,2}, }

- The weighted graph shows edges between nodes along with their respective weights.
*/
