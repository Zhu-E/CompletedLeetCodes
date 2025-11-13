struct comp{
    bool operator()(pair<int, int> left, pair<int, int> right){
        return left.first>right.first;
    }
};

class Solution {
public:
    vector<vector<vector<int>>> constructAdj(vector<vector<int>>& edges, int V){
        vector<vector<vector<int>>> adjacencies(V);
        for(auto i : edges){
            adjacencies[i[0]].push_back({i[1], i[2]});
        }
        return adjacencies;
    }
    int minCost(int n, vector<vector<int>>& edges) {
        vector<vector<int>> trueEdges;
        for(auto i : edges){
            trueEdges.push_back(i);
            trueEdges.push_back({i[1],i[0],2*i[2]});
        }
        vector<vector<vector<int>>> adjs = constructAdj(trueEdges, n);
        vector<int> distances(n, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int, int>>, comp> pq;
        distances[0]=0;
        pq.push({0, 0});
        vector<bool> visited(n, false);
        visited[0]=true;
        while(!pq.empty()){
            int vertex = pq.top().second;
            int curDist = pq.top().first;
            visited[vertex]=true;
            pq.pop();
            for(auto i : adjs[vertex]){
                if(curDist+i[1]<distances[i[0]]&&!visited[i[0]]){
                    distances[i[0]] = curDist+i[1];
                    pq.push({curDist+i[1], i[0]});
                }
            }
        }
        if(distances[n-1]==INT_MAX){
            return -1;
        }
        return distances[n-1]; 
    }
};
