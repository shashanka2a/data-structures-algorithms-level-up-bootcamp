// https://practice.geeksforgeeks.org/problems/inorder-successor-in-bst/1#

/*
Given a BST, and a reference to a Node x in the BST. Find the Inorder Successor of the given node in the BST.
 

Example 1:

Input:
      2
    /   \
   1     3
K(data of x) = 2
Output: 3 
Explanation: 
Inorder traversal : 1 2 3 
Hence, inorder successor of 2 is 3.

Example 2:

Input:
             20
            /   \
           8     22
          / \
         4   12
            /  \
           10   14
K(data of x) = 8
Output: 10
Explanation:
Inorder traversal: 4 8 10 12 14 20 22
Hence, successor of 8 is 10.
*/

class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
        
        if(x->right!=NULL){
            Node* temp = x->right;
            while(temp->left!=NULL){
                temp = temp->left;
            }
            return temp;
        }

        Node* temp = root;
        Node* ans = NULL;
        while(temp!=NULL){
            if(temp->data  > x->data){
                ans = temp;
                temp = temp->left;
            }
            else if(temp->data  < x->data){
                temp = temp->right;
            }
            else{
                break;
            }
        }
        return ans;
    }

};
