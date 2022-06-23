class Solution {
private:
    vector<int> toposort(int n,vector<int> adj[]){
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(int neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> final_ans;
        while(not q.empty()){
            int node = q.front();
            final_ans.push_back(node);
            q.pop();
            
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        return final_ans;
    }
    
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
    
    bool isCyclePresent(int n,vector<int> adj[]){
        vector<int> vis(n);
        vector<int> pathVis(n);
        for(int i=0;i<n;i++){
            if(vis[i]==0){
                if(checkCycleDG(i,adj,vis,pathVis)){
                    return true;
                }
            }
        }
        return false;
    }
    
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u); // change
        }
        
        if(isCyclePresent(n,adj))
            return {};
        else
            return toposort(n,adj);
    }
};

// another method
class Solution {
private:
    vector<int> toposort(int n,vector<int> adj[]){
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(int neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        vector<int> final_ans;
        while(not q.empty()){
            int node = q.front();
            final_ans.push_back(node);
            q.pop();
            
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        
        // atlast if any of indegree is non zero then cycle present 
        for(int i=0;i<n;i++){
            if(indegree[i]!=0){
                return {};
            }
        }
        return final_ans;
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        return toposort(n,adj);
    }
};

// another method
class Solution {
private:
    vector<int> toposort(int n,vector<int> adj[]){
        vector<int> indegree(n);
        for(int i=0;i<n;i++){
            for(int neighbour : adj[i]){
                indegree[neighbour]++;
            }
        }
        
        queue<int> q;
        for(int i=0;i<n;i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
        
        int cnt = 0;
        vector<int> final_ans;
        while(not q.empty()){
            int node = q.front();
            final_ans.push_back(node);
            q.pop();
            cnt++;
            
            for(int neighbour : adj[node]){
                indegree[neighbour]--;
                if(indegree[neighbour]==0){
                    q.push(neighbour);
                }
            }
        }
        
        // if it's valid toposort then queue size should be n
        if(cnt==n)
            return final_ans;
        else
            return {};
    }

public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        int n = numCourses;
        vector<int> adj[n];
        for(int i=0;i<prerequisites.size();i++){
            int u = prerequisites[i][0];
            int v = prerequisites[i][1];
            adj[v].push_back(u);
        }
        return toposort(n,adj);
    }
};