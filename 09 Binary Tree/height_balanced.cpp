// https://leetcode.com/problems/balanced-binary-tree/

/*
Given a binary tree, determine if it is height-balanced.

For this problem, a height-balanced binary tree is defined as:

a binary tree in which the left and right subtrees of every node differ in height by no more than 1.


Input: root = [3,9,20,null,null,15,7]
Output: true

Input: root = [1,2,2,3,3,null,null,4,4]
Output: false

*/


class Solution {
public:
	
    bool isBalanced(TreeNode* root) {
        pair <int,bool> p;
        p = BalancedHelper(root);
        return p.second;
    }
    // Post Order Approach -> Building answer in Bottum-Up Fashion : Optimising by removing height function and passing as pair value
    // For a Tree to be Height Balanced , left should return true and also right.
    pair<int,bool> BalancedHelper(TreeNode* root){
        pair <int,bool> l,r;
        if(root==NULL){
            return make_pair(0,true);
        }
        l = BalancedHelper(root->left);
        r = BalancedHelper(root->right);
        int height = 1 + max(l.first,r.first);
        if(abs(l.first-r.first)<=1 && l.second && r.second){
           return make_pair(height,true);
        }
        return make_pair(height,false);
    }
	
};
