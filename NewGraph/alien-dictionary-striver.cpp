#include<bits/stdc++.h>
using namespace std;

class Solution {
private:
    int getInt(char c){
        return (c-'a');
    }

    bool checkCycle(int node,vector<int> adj[],vector<int> &vis,vector<int> &pathVis,stack<int> &st){
        vis[node] = 1;
        pathVis[node] = 1;

        for(int neighbour : adj[node]){
            if(vis[neighbour]==0){
                if(checkCycle(neighbour,adj,vis,pathVis,st)==true){
                    return true;
                }
            }
            else if(vis[neighbour]==1 && pathVis[neighbour]==1){
                return true;
            }
        }

        pathVis[node] = 0;
        st.push(node);
        return false;
    }

public:
    string alienOrder(vector<string> &words) {
        int n = words.size();
        vector<int> adj[26];

        vector<int> present(26,0);
        vector<int> vis(26,0), pathVis(26,0);

        for(int i=0;i<n;i++){
            for(auto it : words[i]){
                present[getInt(it)] = 1;
            }
        }

        // go through every adjacent pair
        for(int i=1;i<n;i++){
            string s1 = words[i-1];
            string s2 = words[i];
            int n1 = s1.size();

            for(int j=0;j<n1;j++){
                // "raja" & "raj"
                if(j>=s2.size()){
                    return "";
                }

                if(s1[j]!=s2[j]){
                    present[getInt(s1[j])] = 1;
                    present[getInt(s2[j])] = 1;
                    // first mismatch then create DAG
                    adj[getInt(s1[j])].push_back(getInt(s2[j]));
                    // we need only first mismatch
                    break;
                }
            }
        }

        stack<int> st;
        for(int i=0;i<26;i++){
            if(present[i] && vis[i]==0){
                if(checkCycle(i,adj,vis,pathVis,st)==true){
                    return "";
                }
            }
        }

        string ans = "";
        while(not st.empty()){
            ans += char(st.top()+'a');
            st.pop();
        }
        return ans;
    }
};