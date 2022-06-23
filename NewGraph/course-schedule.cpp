// detect cycle in direcetd graph using 2 array (vis & pathVis)
// if cycle present then ans:false else ans:true
class Solution {
private:
    bool checkCycleDG(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis){
        vis[node] = 1;
        pathVis[node] = 1;
        for(int neighbour : adj[node]){
            if(vis[neighbour]==0){
                if(checkCycleDG(neighbour,adj,vis,pathVis)){
                    return true;
                }
            }
            else if(vis[neighbour]==pathVis[neighbour]){
                return true;
            }
        }
        
        pathVis[node] = 0;
        return false;
    }
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        // detect the cycle in directed graph
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        
        vector<int> vis(n);
        vector<int> pathVis(n);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(checkCycleDG(i,adj,vis,pathVis)){
                    // there is cycle in directed graph
                    return false;
                }
            }
        }
        // not found the cycle so ans possible
        return true;
    }
};