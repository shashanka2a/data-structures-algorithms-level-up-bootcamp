// https://practice.geeksforgeeks.org/problems/transform-to-sum-tree/1#
/*
Given a Binary Tree of size N , where each node can have positive or negative values. Convert this to a tree where each node contains the sum of the left and right sub trees of the original tree. The values of leaf nodes are changed to 0.

Example 1:

Input:
             10
          /      \
        -2        6
       /   \     /  \
     8     -4   7    5
     
Output:
            20
          /    \
        4        12
       /  \     /  \
     0     0   0    0
*/

class Solution {
  public:
  
    // Convert a given tree to a tree where every node contains sum of values of
    // nodes in left and right subtrees in the original tree
    void toSumTree(Node *node)
    {
        TreeSum(node);
    }
  
    int TreeSum(Node* root){
        // base case
        if(root==NULL){
            return 0;
        }
        // leaf node
        if(root->left==NULL && root->right==NULL){
            int val = root->data;
            root->data = 0;
            return val;
        }
        // current node sum is left sub-tree sum + right sub-tree sum
        int temp = TreeSum(root->left) + TreeSum(root->right);
        // current sum including node is addition of the temp sum value to the node value
        int sum = temp + root->data;
        // replace the value with the sum of descedents excluding node val ( i.e we store it before assigning to root->data ) 
        root->data = temp;
        return sum;
    }
  
};
