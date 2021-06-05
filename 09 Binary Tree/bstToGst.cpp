// https://leetcode.com/problems/binary-search-tree-to-greater-sum-tree/
/* 

Given the root of a Binary Search Tree (BST), convert it to a Greater Tree such that every key of the original BST is changed to the original key plus sum of all keys greater than the original key in BST.

As a reminder, a binary search tree is a tree that satisfies these constraints:

The left subtree of a node contains only nodes with keys less than the node's key.
The right subtree of a node contains only nodes with keys greater than the node's key.
Both the left and right subtrees must also be binary search tree

Example 2:

Input: root = [0,null,1]
Output: [1,null,1]
Example 3:

Input: root = [1,0,2]
Output: [3,3,2]
Example 4:

Input: root = [3,2,4,1]
Output: [7,9,4,10]

*/


// Approach is to use the concept of Inverse InOrder ( Descending Sorted Array ) 
// and replace current node with prev sum, adding up the current node value to the sum value beforehand.

class Solution {
public:
  
    TreeNode* bstToGst(TreeNode* root) {
 
        InOrder(root,0);
        return root;
        
    }
    
    int InOrder(TreeNode* root,int pre){
        if(root==NULL){
            return 0;
        }
        int sum =  root->val + InOrder(root->right, pre);
        root->val = sum  + pre;
        sum += InOrder(root->left, root->val);
        return sum;
    }
};
