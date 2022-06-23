// bipartite of graph bfs
class Solution {
private:
    bool oddLenCyclePresent(int node,vector<vector<int>> &graph,vector<int> &col){
        queue<int> q;
        q.push(node);
        col[node] = 1;
        
        while(not q.empty()){
            int node = q.front();
            q.pop();
            
            for(int neighbour : graph[node]){
                if(col[neighbour]==-1){
                    col[neighbour] = 1^col[node];
                    q.push(neighbour);
                }
                else if(col[neighbour]!=-1 && col[neighbour]==col[node]){
                    return true; // odd length cycle present
                }
            }
        }
        return false;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(oddLenCyclePresent(i,graph,col)==true){
                    return false; // odd len cycle present : graph is not bipartite
                }
            }
        }
        return true;
    }
};

// bipartite of graph dfs
class Solution {
private:
    bool oddLenCyclePresent(int node,vector<vector<int>> &graph,vector<int> &col){
        if(col[node]==-1) col[node] = 1;
            
        for(int neighbour : graph[node]){
            if(col[neighbour]==-1){
                col[neighbour] = 1^col[node];
                if(oddLenCyclePresent(neighbour,graph,col)==true){
                    return true;
                }
            }
            else if(col[neighbour]!=-1 && col[neighbour]==col[node]){
                return true; // odd length cycle present
            }
        }
        return false;
    }
    
public:
    bool isBipartite(vector<vector<int>>& graph) {
        int n = graph.size();
        vector<int> col(n,-1);
        
        for(int i=0;i<n;i++){
            if(col[i]==-1){
                if(oddLenCyclePresent(i,graph,col)==true){
                    return false; // odd len cycle present : graph is not bipartite
                }
            }
        }
        return true;
    }
};