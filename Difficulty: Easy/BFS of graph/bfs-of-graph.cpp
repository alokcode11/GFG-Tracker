#include <vector>
#include <queue>
using namespace std;

class Solution {
  public:
    vector<int> bfs(vector<vector<int>> &adj) {
        int V = adj.size(); // Total number of vertices
        vector<int> result; // To store the BFS traversal order
        vector<bool> visited(V, false); // To keep track of visited nodes
        queue<int> q; // Queue to manage the BFS level-by-level traversal
        
        // Edge case: if the graph is empty
        if (V == 0) return result;
        
        // Start traversal from node 0
        visited[0] = true;
        q.push(0);
        
        while (!q.empty()) {
            int node = q.front();
            q.pop();
            result.push_back(node);
            
            // Iterate through all adjacent nodes of the current node
            for (int neighbor : adj[node]) {
                // If the neighbor hasn't been visited yet
                if (!visited[neighbor]) {
                    visited[neighbor] = true; // Mark as visited immediately
                    q.push(neighbor);         // Add to queue for future processing
                }
            }
        }
        
        return result;
    }
};