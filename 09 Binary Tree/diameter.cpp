/* 
Given an array of unique elements, construct a Binary Search Tree and find the diameter of the tree. Diameter is defined as the number of nodes on the longest path between 2 nodes of the tree.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 5000
0 <= ar[i] <= 10000


Sample Input 

3
5
1 2 3 4 5 
5
2 4 3 1 5 
7
4 5 15 0 1 7 17 

Sample Output 

5
4
6

*/





#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
using namespace std;
class Node {
    public:
    int data;
    Node *left;
    Node *right;
    Node(int d) {
        data = d;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* h,int k){
    if(h==NULL) 
        return new Node(k);
    if(h->data<k) 
        h->right= insert(h->right,k);
    else 
        h->left=insert(h->left,k);
    return h;
} 

int height(Node* root){
    if(root==NULL)
        return 0;
    return 1+max(height(root->left),height(root->right));
}

// Max of Left Subtree Diameter || Left Subtree + Root + Right Subtree Diameter || Right Subtree Diameter

// Diameter -> no of edges                                Height -> no of node

// d1 = h1-1                    d2 = h2 - 1               D = d1 + d2 + 2 (root edges)

// O ( N ^ 2 ) calling height function recursively leads to multiple calls for single computattion.

int diameter(Node* root){
    if(root==NULL){
        return 0;
    }
    int D1 = height(root->left) + height(root->right);
    int D2 = diameter(root->left);
    int D3 = diameter(root->right);
    
    return max(D1,max(D2,D3));
}



int main() {
    int t;
    cin>>t;
    while(t--){
        int n,x;
        cin>>n;
        Node* root=NULL;
        for(int i=0;i<n;i++){
            cin>>x;
            root=insert(root,x);
        }
        cout<< 1 + diameter(root) <<endl;
    }
    return 0;
}
