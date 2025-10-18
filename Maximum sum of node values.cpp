#include <bits/stdc++.h>
using namespace std;

// Definition for a binary tree node
struct Node {
    int data;
    Node* left;
    Node* right;
    Node(int val) {
        data = val;
        left = right = nullptr;
    }
};

class Solution {
    int maxSum; // Global maximum sum
    // Helper function to compute maximum gain from a node
    int findMaxPath(Node* root) {
        if (!root) return 0;

        int leftGain = max(0, findMaxPath(root->left));  // Max path sum from left
        int rightGain = max(0, findMaxPath(root->right)); // Max path sum from right

        // Update global maximum including current node
        maxSum = max(maxSum, leftGain + rightGain + root->data);

        // Return max gain including current node for recursion
        return root->data + max(leftGain, rightGain);
    }

public:
    int maxPathSum(Node* root) {
        maxSum = INT_MIN;
        findMaxPath(root);
        return maxSum;
    }
};

// Example usage
int main() {
    /*
         10
        /  \
       2   10
      / \    \
     20  1   -25
              /  \
             3    4
    Expected Output: 42 (20 + 2 + 10 + 10)
    */

    Node* root = new Node(10);
    root->left = new Node(2);
    root->right = new Node(10);
    root->left->left = new Node(20);
    root->left->right = new Node(1);
    root->right->right = new Node(-25);
    root->right->right->left = new Node(3);
    root->right->right->right = new Node(4);

    Solution sol;
    cout << "Maximum Path Sum: " << sol.maxPathSum(root) << endl;

    return 0;
}
