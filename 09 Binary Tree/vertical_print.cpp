// https://www.hackerrank.com/contests/smart-interviews/challenges/si-vertical-order-of-tree/problem
/*

Given an array of unique elements, construct a Binary Search Tree and print the tree in a Vertical Order, starting from the left-most node. Print the nodes in each vertical in sorted order.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
0 <= ar[i] <= 10000

Output Format

For each test case, print the Vertical Levels of the Binary Search Tree, separate each level by newline. Separate the output of different test cases with an extra newline.

Sample Input 0

3
5
1 2 3 4 5 
5
3 1 2 5 4 
7
4 5 15 0 1 7 17 

Sample Output 0

1 
2 
3 
4 
5 

1 
2 3 4 
5 

0 
1 4 
5 7 
15 
17

*/

#include <iostream>
#include <algorithm>
#include <map>
#include <set>
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

void Helper(Node* root,int d,map<int,set<int>> &m){
    if(root==NULL){
       return; 
    }
    m[d].insert(root->data);
    Helper(root->left,d-1,m);
    Helper(root->right,d+1,m);
    
}

// Vertical Level means distance from root node
// Left side travesal is negative distance ( -1 ) 
// Right side traversal postive distance ( +1 ) 
// Store the level wise node values in a map of int,set<int>
// InOrder Approach -> Building Solution in Top-Down Fashion

void printVerticalOrder(Node* root){
    map<int,set<int>> m;
    Helper(root,0,m);
    for(auto p:m){
        set<int> s = p.second;
        for(auto i:s){
            cout<<i<<" ";
        }
        cout<<endl;
    }
}

int main() {
    int T;
    cin>>T;
    while(T--){
        int n;
        int x;
        cin>>n;
        Node *root = NULL;
        for(int i=0;i<n;i++){
            cin>>x;
            root = insert(root,x);
        }
        printVerticalOrder(root);
        cout<<endl;
    }
    return 0;
}
