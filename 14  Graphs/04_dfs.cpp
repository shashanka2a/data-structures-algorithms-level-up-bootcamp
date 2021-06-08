// https://practice.geeksforgeeks.org/problems/depth-first-traversal-for-a-graph/1#
/*
Given a connected undirected graph. Perform a Depth First Traversal of the graph.
Note: Use recursive approach to find the DFS traversal of the graph starting from the 0th vertex from left to right according to the graph.
*/

class Solution
{
	void dfs(int node, vector<int> adj[],vector<int> &vis,vector<int> &nodes){
        nodes.push_back(node);
        //cout<< node<<" ";
        vis[node] = 1;
        
        for (auto i:adj[node]){
            if (!vis[i]) {
                dfs(i, adj, vis, nodes); 
            }
        }
    }

   public:
   	//Function to return a list containing the DFS traversal of the graph.
   	vector<int>dfsOfGraph(int V, vector<int> adj[])
	{
	    vector<int> nodes;
        vector<int> vis(V,0);
	    for(int i=0;i<V;i++){
	        if(vis[i]==0){
	            dfs(i,adj,vis,nodes);
	        }
	    }
	    return nodes;
	}
};
