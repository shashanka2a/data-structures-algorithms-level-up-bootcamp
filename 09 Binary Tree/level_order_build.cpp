#include<iostream>
#include<queue>
using namespace std;

class Node{

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

//Input : 1 2 4 5 7 3 6 
Node* insert(Node* root,int arr[],int i, int n) 
{ 
    if (i < n) 
    { 
        Node* temp = new Node(arr[i]); 
        root = temp; 
        root->left = insert(root->left,arr,2 * i + 1, n); 
        root->right = insert(root->right,arr,2 * i + 2, n); 
    } 
    return root; 
}

/*Level Order Traversal
Expected Output

1
2 3
4 5 6
7
*/


int main(){
        int a[n];
        Node *root = NULL;  
        for(int i=0;i<n;i++)
            cin>>a[i];
        root = insert(root,a,0,n);

	return 0;
}
