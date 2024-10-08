#include <iostream>
#include <unordered_map>
#include <list>
#include <queue>
#include <map>
#include <algorithm>
using namespace std;

class Graph {
public:
    // 🎯 Adjacency list representation of the graph
    unordered_map<int, list<int>> adjacencyLists;

    // ✨ Function to add edges between nodes (directed or undirected)
    void addEdges(int sourceNode, int destinationNode, bool isDirected) {
        if (isDirected == 1) {
            // ➡️ Directed graph: Add edge from source to destination
            adjacencyLists[sourceNode].push_back(destinationNode);
        } else {
            // 🔄 Undirected graph: Add edges in both directions
            adjacencyLists[sourceNode].push_back(destinationNode);
            adjacencyLists[destinationNode].push_back(sourceNode);
        }
    }

    // 🖨️ Function to print the adjacency list of the graph
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

    // 🧭 Function to find the shortest path between two nodes in an undirected graph using BFS
    // Algorithm:
    // 1️⃣ Start BFS traversal from the source node.
    // 2️⃣ Keep track of visited nodes and their parent nodes.
    // 3️⃣ When you reach the destination, backtrack using the parent map to find the shortest path.
    // 4️⃣ Reverse the path to get the correct order from source to destination.
    vector<int> shortestPathInUndirectedGraph(int src, int dest) {
        queue<int> q;              // Queue for BFS
        map<int, bool> isVisited;   // Map to track visited nodes
        map<int, int> parent;       // Map to store parent of each node (to backtrack the path)

        // 🌟 Initialize BFS from source
        q.push(src);
        isVisited[src] = true;
        parent[src] = -1;  // Source node has no parent

        // 🔄 Perform BFS traversal
        while (!q.empty()) {
            int frontNode = q.front();
            q.pop();

            // Explore all neighbors of the current node
            for (auto nbr : adjacencyLists[frontNode]) {
                if (!isVisited[nbr]) {
                    q.push(nbr);          // Push neighbor to queue
                    parent[nbr] = frontNode;  // Set parent of the neighbor
                    isVisited[nbr] = true;    // Mark neighbor as visited
                }
            }
        }

        // 📍 Trace the shortest path by backtracking from the destination node using the parent map
        vector<int> shortestPath;

        while (dest != -1) {
            shortestPath.push_back(dest);  // Add current node to path
            dest = parent[dest];           // Move to the parent node
        }

        // 🌟 Since we backtracked, the path is reversed, so reverse it to get the correct order
        reverse(shortestPath.begin(), shortestPath.end());

        return shortestPath;  // Return the final shortest path
    }

};

int main() {
    Graph g;

    // 🎯 Adding undirected edges to the graph
    g.addEdges(0, 5, 0);  
    g.addEdges(5, 4, 0);  
    g.addEdges(4, 3, 0);  
    g.addEdges(0, 6, 0);  
    g.addEdges(6, 3, 0);  
    g.addEdges(0, 1, 0);  
    g.addEdges(1, 2, 0);  
    g.addEdges(2, 3, 0);  

    // 🖨️ Print the adjacency list of the graph
    g.printAdjacencyList();

    // 🎯 Find the shortest path between src and dest
    int src = 0, dest = 3;
    cout << "Shortest path between " << src << " and " << dest << ": ";

    // Output the path
    for (auto path : g.shortestPathInUndirectedGraph(src, dest)) {
        cout << path << "->";
    }

    cout << "end" << endl;
    return 0;
}

/*
📋 Sample Output:

0 -> { 5, 6, 1, }
5 -> { 0, 4, }
4 -> { 5, 3, }
3 -> { 4, 6, 2, }
6 -> { 0, 3, }
1 -> { 0, 2, }
2 -> { 1, 3, }
Shortest path between 0 and 3: 0->6->3->end

Explanation:
1️⃣ The graph is undirected, and we add edges between nodes accordingly.
2️⃣ The BFS algorithm starts from the source node (0) and explores the graph level by level.
3️⃣ The `parent` map is used to backtrack from the destination node (3) to find the shortest path.
4️⃣ The shortest path from 0 to 3 is found by traversing
the parent map, and the nodes traversed in this path are 0 -> 6 -> 3.
5️⃣ Since BFS explores level by level, it ensures that the first time we reach the destination node, we have found the shortest possible path in terms of the number of edges.
*/

/*
⏲️ Time Complexity:
- Adding edges: O(1) for each edge.
- BFS traversal: O(V + E), where V is the number of vertices, and E is the number of edges.
- Finding the shortest path by backtracking: O(V), as we potentially visit every node once.
Overall complexity: O(V + E).

📦 Space Complexity:
- Space used by the adjacency list: O(V + E), as we store each edge for each vertex.
- Space used by the BFS queue and maps: O(V), since we visit each node and store its parent and visited status.
*/