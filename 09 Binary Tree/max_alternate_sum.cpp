// https://www.hackerrank.com/contests/smart-interviews/challenges/si-maximum-alternate-nodes-sum/problem

/*
Given an array of unique elements, construct a Binary Search Tree and find the maximum sum of nodes, with the constraint that if you select a node, you cannot select any of its immediate child nodes.

Input Format

First line of input contains T - number of test cases. Its followed by 2T lines. First line of each test case contains N - number of nodes in the BST. The next line contains N unique integers - value of the nodes.

Constraints

1 <= T <= 1000
1 <= N <= 1000
-10000 <= ar[i] <= 10000

Output Format

For each test case, print the maximum sum, separated by newline.

Sample Input 0

5
5
1 2 3 4 5 
7
4 5 15 0 1 7 17 
5
4 1 3 5 2 
9
6472 -3661 -2660 5275 3009 1733 5234 4191 6812 
12
8827 93 1794 -6354 -2386 -2985 1460 7095 8778 4958 52 5284 
Sample Output 0

9
30
8
19054
24735

*/


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

// include current node       exclude current node
//       |			       |
//    p.first                       p.second
// Post Order -> Building Solution in Bottum-Up Fashion

pair<int,int> Helper(Node* root){
        pair <int,int> p,l,r;
        if(root==NULL){
            return make_pair(0,0);
        }
        l = Helper(root->left);
        r = Helper(root->right);
        p.first = root->data + l.second + r.second;
        p.second = max(l.first,l.second) + max(r.first,r.second);
        return p;
    }

int MaxAlternateNodesSum(Node* root){
        pair <int,int> p;
        p = Helper(root);
        return max(p.first,p.second);
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
        cout<< MaxAlternateNodesSum(root) <<endl;
    }
    return 0;
}
