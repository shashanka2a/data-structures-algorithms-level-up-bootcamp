#include<iostream>
#include<list>
#include<queue>
using namespace std;

vector<int> nodes;

void DFS(vector<vector<int>> &alist,int node,vector<int> &vis){
    vis[node] = 1; 
    nodes.push_back(node);
    for (auto i = alist[node].begin(); i != alist[node].end(); i++) 
        if (!vis[*i]) 
            DFS(alist,*i, vis); 
}

int main(){
	int V,E;
	scanf("%d%d",&V,&E);
	vector<vector<int>> alist(V+1);
	for(int i=0;i<E;i++){
	    int u,v;
	    scanf("%d%d",&u,&v);
	    alist[u].push_back(v);
	    alist[v].push_back(u);
	}
	vector<int> vis(V+1,0);
	for(int i=1;i<=V;i++)
	    if(vis[i]!=1){
		DFS(alist,i,vis);
	    }
	for(auto i = nodes.begin(); i != nodes.end(); i++){
	    cout<<*i<<" ";
	}
	cout<<endl;

}
