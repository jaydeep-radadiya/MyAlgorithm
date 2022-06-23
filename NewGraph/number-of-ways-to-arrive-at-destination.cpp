class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        int mod = 1e9+7;
        vector<long long> ways(n,0);
        vector<long long> dist(n,1e18);
        dist[0] = 0;
        ways[0] = 1;
        
        // build graph
        vector<pair<long long,long long>> adj[n];
        for(auto &it : roads){
            adj[it[0]].push_back({it[1],it[2]});
            adj[it[1]].push_back({it[0],it[2]});
        }
        
        priority_queue<pair<long long,long long>,vector<pair<long long,long long>>,greater<pair<long long,long long>>> minh;
        minh.push({0,0});
        while(not minh.empty()){
            long long d = minh.top().first;
            long long node = minh.top().second;
            minh.pop();
            
            for(auto &it : adj[node]){
                long long adjnode = it.first;
                long long wt = it.second;
                if(wt+d<dist[adjnode]){
                    dist[adjnode] = wt+d;
                    ways[adjnode] = ways[node];
                    minh.push({dist[adjnode],adjnode});
                }
                else if(wt+d==dist[adjnode]){
                    ways[adjnode] = (ways[adjnode]+ways[node])%mod;
                }
            }
        }
        return ways[n-1];
    }
};