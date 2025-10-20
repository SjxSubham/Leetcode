/*
Problem: 133. Clone Graph (Medium)
Link: https://leetcode.com/problems/clone-graph/

Concepts: Graphs, DFS, BFS, Hash Map
Difficulty: Medium

Problem Statement:
Given a reference of a node in a connected undirected graph, return a deep copy (clone) of the graph.
Each node in the graph contains a value (int) and a list (List[Node]) of its neighbors.

Test case format:
For simplicity, each node's value is the same as the node's index (1-indexed). 
For example, the first node with val == 1, the second node with val == 2, and so on.

Example 1:
Input: adjList = [[2,4],[1,3],[2,4],[1,3]]
Output: [[2,4],[1,3],[2,4],[1,3]]
Explanation: 
Graph with 4 nodes:
1 -- 2
|    |
4 -- 3

Example 2:
Input: adjList = [[]]
Output: [[]]
Explanation: Single node with no neighbors.

Example 3:
Input: adjList = []
Output: []
Explanation: Empty graph.

Approach 1 - DFS (Depth-First Search):
1. Use a hash map to track visited nodes and their clones.
2. For each node, create a clone if not already created.
3. Recursively clone all neighbors.
4. Add cloned neighbors to the current clone's neighbor list.

Approach 2 - BFS (Breadth-First Search):
1. Use a hash map to track visited nodes and their clones.
2. Use a queue for BFS traversal.
3. For each node, clone it and its neighbors level by level.

Time Complexity: O(N + E) where N = number of nodes, E = number of edges
Space Complexity: O(N) for the hash map and recursion stack/queue
*/

#include <vector>
#include <unordered_map>
#include <queue>
using namespace std;

// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> neighbors;
    
    Node() {
        val = 0;
        neighbors = vector<Node*>();
    }
    
    Node(int _val) {
        val = _val;
        neighbors = vector<Node*>();
    }
    
    Node(int _val, vector<Node*> _neighbors) {
        val = _val;
        neighbors = _neighbors;
    }
};

// Approach 1: DFS (Recursive) - Recommended
class Solution {
private:
    // Hash map to store original node -> cloned node mapping
    unordered_map<Node*, Node*> visited;
    
public:
    Node* cloneGraph(Node* node) {
        // Base case: if node is null, return null
        if (node == nullptr) {
            return nullptr;
        }
        
        // If node is already cloned, return the clone
        if (visited.find(node) != visited.end()) {
            return visited[node];
        }
        
        // Create a clone of the current node
        Node* cloneNode = new Node(node->val);
        
        // Store the clone in the hash map before recursing
        // This prevents infinite loops in cyclic graphs
        visited[node] = cloneNode;
        
        // Recursively clone all neighbors
        for (Node* neighbor : node->neighbors) {
            cloneNode->neighbors.push_back(cloneGraph(neighbor));
        }
        
        return cloneNode;
    }
};

// Approach 2: BFS (Iterative)
class SolutionBFS {
public:
    Node* cloneGraph(Node* node) {
        // Base case: if node is null, return null
        if (node == nullptr) {
            return nullptr;
        }
        
        // Hash map to store original node -> cloned node mapping
        unordered_map<Node*, Node*> visited;
        
        // Queue for BFS
        queue<Node*> q;
        
        // Clone the starting node and add to queue
        Node* cloneNode = new Node(node->val);
        visited[node] = cloneNode;
        q.push(node);
        
        // BFS traversal
        while (!q.empty()) {
            Node* current = q.front();
            q.pop();
            
            // Process all neighbors
            for (Node* neighbor : current->neighbors) {
                // If neighbor hasn't been cloned yet
                if (visited.find(neighbor) == visited.end()) {
                    // Clone the neighbor
                    visited[neighbor] = new Node(neighbor->val);
                    // Add to queue for further processing
                    q.push(neighbor);
                }
                
                // Add the cloned neighbor to current clone's neighbor list
                visited[current]->neighbors.push_back(visited[neighbor]);
            }
        }
        
        return cloneNode;
    }
};

/*
Detailed Example Walkthrough (DFS):

Graph:
  1 -- 2
  |    |
  4 -- 3

Adjacency List: [[2,4],[1,3],[2,4],[1,3]]

Step-by-step DFS execution:

1. cloneGraph(node1):
   - visited = {node1: clone1}
   - Process neighbors [node2, node4]

2. cloneGraph(node2):
   - visited = {node1: clone1, node2: clone2}
   - Process neighbors [node1, node3]
   
3. cloneGraph(node1):
   - Already in visited, return clone1
   - clone2.neighbors = [clone1]

4. cloneGraph(node3):
   - visited = {node1: clone1, node2: clone2, node3: clone3}
   - Process neighbors [node2, node4]

5. cloneGraph(node2):
   - Already in visited, return clone2
   - clone3.neighbors = [clone2]

6. cloneGraph(node4):
   - visited = {node1: clone1, node2: clone2, node3: clone3, node4: clone4}
   - Process neighbors [node1, node3]

7. Both node1 and node3 already visited
   - clone4.neighbors = [clone1, clone3]
   - clone3.neighbors = [clone2, clone4]

8. Back to step 2:
   - clone2.neighbors = [clone1, clone3]

9. Back to step 4:
   - clone1.neighbors = [clone2, clone4]

Final cloned graph matches original structure!

Key Insights:
1. We MUST store the clone in visited BEFORE processing neighbors to handle cycles.
2. DFS is more intuitive and uses less code.
3. BFS is more explicit about the traversal order.
4. Both approaches handle cyclic graphs correctly.

Common Mistakes to Avoid:
1. Not checking if node is already visited (causes infinite loop in cycles)
2. Cloning nodes after recursion (causes incorrect connections)
3. Not handling null input
4. Creating multiple clones of the same node

Test Cases:
1. adjList = [[2,4],[1,3],[2,4],[1,3]] → 4-node connected graph
2. adjList = [[]] → Single node with no neighbors
3. adjList = [] → Empty graph
4. adjList = [[2],[1]] → Two connected nodes
*/
