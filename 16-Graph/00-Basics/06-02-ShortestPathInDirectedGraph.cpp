#include <iostream>
#include <unordered_map>
#include <list>
#include <stack>
#include <vector>
#include <climits>
using namespace std;

// ✨ Class to represent a Weighted Graph
template<typename T>
class WeightedGraph {
public:
    // Adjacency list with weights represented as a pair (neighbor, weight)
    unordered_map<T, list<pair<T, int>>> adjLists;

    // 🎯 Algorithm for adding an edge:
    // Time Complexity (TC): O(1) per insertion.
    // Space Complexity (SC): O(E), where E is the number of edges.
    void addEdgeToWeightedGraph(T sourceNode, T destinationNode, int weight, bool isDirected) {
        adjLists[sourceNode].push_back(make_pair(destinationNode, weight));
        if (!isDirected) {
            adjLists[destinationNode].push_back(make_pair(sourceNode, weight));
        }
    }

    // 🎯 Algorithm for topological sorting using DFS:
    // Time Complexity (TC): O(V + E), where V is the number of vertices and E is the number of edges.
    // Space Complexity (SC): O(V), due to the recursion stack and the visited array.
    void topologicalSortingDFS(int src, stack<int>& topoStack, unordered_map<int, bool>& isVisited) {
        // Mark the node as visited
        isVisited[src] = true;

        // Visit all the neighbors of the current node
        for (auto neighborPair : adjLists[src]) {
            int neighborNode = neighborPair.first;
            if (!isVisited[neighborNode]) {
                topologicalSortingDFS(neighborNode, topoStack, isVisited);
            }
        }

        // Once all neighbors are visited, push the node to the topological stack
        topoStack.push(src);
    }

    // 🎯 Algorithm for calculating the shortest path using DFS (after topological sort):
    // Time Complexity (TC): O(V + E), where V is the number of vertices and E is the number of edges.
    // Space Complexity (SC): O(V), due to the distance array and stack.
    void shortestPathDFS(stack<int>& topoStack, int src, int n) {
        // Initialize distance array with infinity
        vector<int> dist(n, INT_MAX);
        dist[src] = 0;  // Source node has distance 0

        // Process each node in topological order
        while (!topoStack.empty()) {
            int node = topoStack.top();
            topoStack.pop();

            // If the current node's distance is not infinity, process its neighbors
            if (dist[node] != INT_MAX) {
                for (auto neighborPair : adjLists[node]) {
                    int neighborNode = neighborPair.first;
                    int weight = neighborPair.second;

                    // Relax the edge
                    if (dist[node] + weight < dist[neighborNode]) {
                        dist[neighborNode] = dist[node] + weight;
                    }
                }
            }
        }

        // 🖨️ Print the calculated shortest distances
        cout << "Shortest distances from node " << src << ": ";
        for (int i = 0; i < n; i++) {
            if (dist[i] == INT_MAX) {
                cout << "INF ";
            } else {
                cout << dist[i] << " ";
            }
        }
        cout << endl;
    }
};

int main() {
    // 🎯 Create a Weighted Graph
    WeightedGraph<int> wg;

    // 🎯 Add directed edges with weights to the graph
    wg.addEdgeToWeightedGraph(0, 1, 5, 1); // 0 -> 1 with weight 5
    wg.addEdgeToWeightedGraph(0, 2, 3, 1); // 0 -> 2 with weight 3
    wg.addEdgeToWeightedGraph(1, 3, 6, 1); // 1 -> 3 with weight 6
    wg.addEdgeToWeightedGraph(2, 3, 7, 1); // 2 -> 3 with weight 7
    wg.addEdgeToWeightedGraph(2, 4, 4, 1); // 2 -> 4 with weight 4
    wg.addEdgeToWeightedGraph(3, 4, 2, 1); // 3 -> 4 with weight 2
    wg.addEdgeToWeightedGraph(4, 5, 1, 1); // 4 -> 5 with weight 1

    // 🎯 Perform topological sorting using DFS
    stack<int> topoStack;
    unordered_map<int, bool> isVisited;
    int n = 6;

    for (int i = 0; i < n; i++) {
        if (!isVisited[i]) {
            wg.topologicalSortingDFS(i, topoStack, isVisited);
        }
    }

    // 🎯 Calculate the shortest paths from node 0
    int src = 0;
    wg.shortestPathDFS(topoStack, src, n);

    return 0;
}
