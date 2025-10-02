class Solution {
public:
    int countRestrictedPaths(int n, vector<vector<int>>& edges) {
        vector<int> dist(n+1, INT_MAX);
        priority_queue<vector<int>, vector<vector<int>>, greater<vector<int>>> pq;
        vector<vector<vector<int>>> adj = makeAdjacency(edges, n);
        int src = n;
        pq.push({0, src});
        dist[src] = 0;
        while(!pq.empty()){
            int u = pq.top()[1];
            pq.pop();
            for (auto x : adj[u]){
                int v = x[0];
                int weight = x[1];
                if (dist[v] > dist[u] + weight)
                {
                    dist[v] = dist[u] + weight;
                    pq.push({dist[v], v});
                }
            }
        }
        vector<int> dp(n+1, INT_MIN);
        return backtrack(n, adj, dist, dp);
    }
    vector<vector<vector<int>>> makeAdjacency(vector<vector<int>>& edges,int n){
        vector<vector<vector<int>>> adjacencyMatrix(n+1, vector<vector<int>>());
        for(auto i : edges){
            // cout<<adjacencyMatrix.size()<<" "<<i[0]<<endl;
            adjacencyMatrix[i[0]].push_back({i[1],i[2]});
            adjacencyMatrix[i[1]].push_back({i[0],i[2]});
        }
        return adjacencyMatrix;
    }
    int backtrack(int src, vector<vector<vector<int>>>& adj, vector<int>& dist, vector<int>& dp){
        int ans = 0;
        if(src == 1){
            return 1;
        }
        if(dp[src]!=INT_MIN){
            return dp[src];
        }
        for(auto i : adj[src]){
            if(dist[i[0]]>dist[src]){
                ans = (ans+backtrack(i[0], adj, dist, dp))%1000000007;
            }
        }
        dp[src]=ans;
        return ans;
    }
};
