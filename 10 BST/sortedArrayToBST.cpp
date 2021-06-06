//  https://leetcode.com/problems/convert-sorted-array-to-binary-search-tree/

/*
Given an integer array nums where the elements are sorted in ascending order, convert it to a height-balanced binary search tree.

A height-balanced binary tree is a binary tree in which the depth of the two subtrees of every node never differs by more than one.

Example 1:

Input: nums = [-10,-3,0,5,9]
Output: [0,-3,9,-10,null,5]
Explanation: [0,-10,5,null,-3,null,9] is also accepted:
*/

class Solution {
public:
    TreeNode* sortedArrayToBST(vector<int>& nums) {
        return Helper(nums,0,nums.size()-1);
    }
    
    TreeNode* Helper(vector<int> nums,int s,int e){
        // base condition
        if(s > e){
            return NULL;
        }
        
        /* Get the middle element and make it root */
        int mid = (s + e)/2; 
        TreeNode *root = new TreeNode(nums[mid]); 
        
        //create left & right subtrees recursively
        root->left = Helper(nums, s, mid - 1); 
        root->right = Helper(nums, mid + 1, e); 

        return root; 
    } 
    
};
