// https://practice.geeksforgeeks.org/problems/find-the-closest-element-in-bst/1#

/*
Given a BST and an integer. Find the least absolute difference between any node value of the BST and the given integer.

Example 1:

Input:
        10
      /   \
     2    11
   /  \ 
  1    5
      /  \
     3    6
      \
       4
K = 13
Output: 2
Explanation: K=13. The node that has
value nearest to K is 11. so the answer
is 2
Example 2:

Input:
      8
    /   \
   1     9
    \     \
     4    10
    /
   3
K = 9
Output: 0
Explanation: K=9. The node that has
value nearest to K is 9. so the answer
is 0.
*/

class Solution
{
    public:
    //Function to find the least absolute difference between any node
	//value of the BST and the given integer.
    int minDiff(Node *root, int K)
    {
        //Your code here
        int diff = INT_MAX;
        Node* temp = root;
        while(temp!=NULL){
            int currdiff = abs(temp->data-K);
            diff = min(diff,currdiff);
            if(temp->data<K){
                temp = temp->right;
            }
            else{
                temp = temp->left;
            }
        }
        return diff;
    }
};
