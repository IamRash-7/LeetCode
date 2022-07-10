// { Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

 // } Driver Code Ends


class Solution
{
	public:
	struct node 
	{
        int u;
        int v;
        int wt; 
        node(int first, int second, int weight) 
        {
            u = first;
            v = second;
            wt = weight;
        }
	};
	
	int findPar(int x, vector<int> &parent)
	{
	    if(x == parent[x]) 
	    return x;
    
        return parent[x] = findPar(parent[x], parent);
    }
    
    void unionn(int u, int v, vector<int> &parent, vector<int> &rank) 
    {
        u = findPar(u, parent);
        v = findPar(v, parent);
        if(rank[u] < rank[v]) 
        {
        	parent[u] = v;
        }
        else if(rank[v] < rank[u]) 
        {
        	parent[v] = u; 
        }
        else {
        	parent[v] = u;
        	rank[u]++; 
        }
    }
    
	//Function to find sum of weights of edges of the Minimum Spanning Tree.
    int spanningTree(int V, vector<vector<int>> adj[])
    {
        // PRIM
        /*
        vector<int> distance(V,INT_MAX);
        vector<int> visited(V,false);
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        // {weight,index}
        
        distance[0]=0;
        pq.push({0,0});
        while(!pq.empty())
        {
            int u = pq.top().second;
            pq.pop();
            
            visited[u] = true;
            for(auto itr:adj[u])
            {
                int v = itr[0];
                int w = itr[1];
                
                if(visited[v]==false && distance[v]>w)
                {
                    distance[v] = w;
                    pq.push({w,v});
                    
                }
            }
        }
        
        int sum = 0;
        for(int i:distance)
        sum+= i;
        return sum;
        */
        
        vector<node> edges;
        for(int i = 0; i<V; i++)
        {
            for(auto it : adj[i])
            {
                int u = i;
                int v = it[0];
                int wt = it[1];
                edges.push_back(node(u, v, wt));
            }
        }
        
        sort(edges.begin(), edges.end(), [](node a, node b){
	        return (a.wt<b.wt);
	    }); 
	    
    	int N = V+1;
    	vector<int> parent(N);
    	
    	for(int i = 0;i<N;i++) 
    	    parent[i] = i; 
    	    
    	vector<int> rank(N, 0); 
    	int sum = 0;
    	
    	for(auto it: edges)
    	{
            if(findPar(it.u, parent)!=findPar(it.v, parent))
            {
                unionn(it.u, it.v, parent, rank);
                sum+=it.wt;
            }
        }
	    
	    return sum;
    }
};

// { Driver Code Starts.


int main()
{
    int t;
    cin >> t;
    while (t--) {
        int V, E;
        cin >> V >> E;
        vector<vector<int>> adj[V];
        int i=0;
        while (i++<E) {
            int u, v, w;
            cin >> u >> v >> w;
            vector<int> t1,t2;
            t1.push_back(v);
            t1.push_back(w);
            adj[u].push_back(t1);
            t2.push_back(u);
            t2.push_back(w);
            adj[v].push_back(t2);
        }
        
        Solution obj;
    	cout << obj.spanningTree(V, adj) << "\n";
    }

    return 0;
}

  // } Driver Code Ends