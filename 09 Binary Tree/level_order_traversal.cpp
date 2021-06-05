#include<iostream>
#include<queue>
using namespace std;

class node{

public:
	int data;
	node*left;
	node*right;
	
	node(int d){
		data = d;
		left = NULL;
		right = NULL;
	}
};

//Input : 1 2 4 -1 -1 5 7 -1 -1 -1 3 -1 6 -1 -1
node* buildTree(){

	int d;
	cin>>d;

	if(d==-1){
		return NULL;
	}

	node* n = new node(d);
	n->left = buildTree();
	n->right = buildTree();

	return n;
}
/* Todo: Implement Level Order Traversal
Expected Output

1
2 3
4 5 6
7
*/


void printLevelOrder(Node* root)  
{  
    queue<Node*> q;
    q.push(root);
    q.push(NULL);
    
    while(q.size()!=0){
        Node* temp = q.front();
        if(temp==NULL){
            cout<<endl;
            q.pop();
            //check if it is not the last NULL , i.e still elements are there in queue to be proccessed.
            if(q.size()!=0){
                q.push(NULL);
            }
        }
        else{
            //Pop the present element and push its children to the queue.
            q.pop();
            cout << temp->data << " ";
            if(temp->left!=NULL){
                q.push(temp->left);
            }
            if(temp->right!=NULL){
                q.push(temp->right);
            }
            
        }
    }

}  


int main(){
	node* root = buildTree();
	printlevelOrder(root);
	return 0;
}
