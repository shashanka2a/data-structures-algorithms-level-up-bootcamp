// https://www.hackerrank.com/contests/smart-interviews/challenges/si-least-common-ancestor/

#include<bits/stdc++.h>
using namespace std;

class Node{
    public:
        int data;
        Node* left;
        Node* right;
    Node(int x){
        data = x;
        left = NULL;
        right = NULL;
    }
};

Node* insert(Node* root,int k){
    if(root==NULL){
        return new Node(k);
    }
    else if(k <= root->data){
        root->left = insert(root->left,k);
    }
    else{
        root->right = insert(root->right,k);
    }
    return root;
}

int height(Node* root){
    if(root==NULL){
        return 0;
    }
    return 1+ max(height(root->left),height(root->right));
}

vector<int> path;
Node* search(Node* root,int k){
    if(root==NULL || root->data == k){
        //cout<< root->data <<" ";
        path.push_back(root->data);
        return root;
    }
    else if(k < root->data){
        path.push_back(root->data);
        //cout<< root->data <<" ";
        return search(root->left,k);
    }
    path.push_back(root->data);
    //cout<< root->data <<" ";
    return search(root->right,k);
    
}


int main() {
    int t;
    cin>>t;
    while(t--){
        int n,q;
        cin>>n>>q;
        Node* root=NULL;
        for(int i=0;i<n;i++){
            int k;
            cin>>k;
            root = insert(root,k);
        }
        while(q--){
            int u,v;
            int res;
            cin>>u>>v;
            vector<int> path1,path2;
            search(root,u);
            path1 = path;
            path.clear();
            /*for(auto i:path1){
                cout<<i<<" ";
            }*/
            //cout<<endl;
            search(root,v);
            path2 = path;
            /*for(auto i:path2){
                cout<<i<<" ";
            }*/
            path.clear();
            //cout<<endl;
            for(auto i:path1){
                for(auto j:path2){
                    //stores last equal nodes in path
                    if(i==j){
                        res = i;
                    }
                }
            }
            cout<<res<<" ";
        }
        cout<<endl;
    }
    return 0;
}


