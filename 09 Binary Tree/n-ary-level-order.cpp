// https://leetcode.com/problems/n-ary-tree-level-order-traversal
/*
// Definition for a Node.
class Node {
public:
    int val;
    vector<Node*> children;

    Node() {}

    Node(int _val) {
        val = _val;
    }

    Node(int _val, vector<Node*> _children) {
        val = _val;
        children = _children;
    }
};
*/

class Solution {
public:
    vector<vector<int>> levelOrder(Node* root) {
        vector<vector<int>> v;
        if(root==NULL){
            //v.push_back({});
            return v;
        }
        queue <Node*> q;
        vector<int> nodes;
        q.push(root);
        //cout<<root->val<<" ";
        v.push_back({root->val});
        q.push(NULL);
        //cout<<endl;

       while(!q.empty()){
            Node* temp = q.front();
            
            if(temp!=NULL){
                if(temp->children.size()!=0){
                    for(auto i: temp->children){
                        q.push(i);
                        //cout<<i->val<<" ";
                        nodes.push_back(i->val);
                    }
                }
                q.pop(); 
            }
            else {
                q.pop();
                //cout<<endl;
                if(q.empty()){
                    break;
                }
                else{
                    v.push_back(nodes);
                    nodes.clear();
                    q.push(NULL);  
                }
            }
        }
        return v;
    }
};
