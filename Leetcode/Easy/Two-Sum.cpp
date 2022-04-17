// tc : O(n^2) sc : O(1)
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        
        for(int i=0;i<n;i++){
            for(int j=i+1;j<n;j++){
                if(arr[i]+arr[j]==target){
                    return {i,j};
                }
            }
        }
        return {-1,-1};
    }
};

// tc : O(nlogn) sc : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        vector<pair<int,int>> temp;
        for(int i=0;i<n;i++){
            temp.push_back({arr[i],i});
        }
        
        sort(temp.begin(),temp.end());
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int sum = temp[left].first+temp[right].first;
            if(sum==target) return {temp[left].second,temp[right].second};
            else if(sum>target) right--;
            else if(sum<target) left++;
        }
        return {-1,-1};
    }
};

// tc : O(n) sc : O(n)
class Solution {
public:
    vector<int> twoSum(vector<int>& arr, int target) {
        int n = arr.size();
        unordered_map<int,int> ump;
        
        for(int i=0;i<n;i++){
            int req = target-arr[i]; // required ele
            if(ump.find(req)!=ump.end()){
                return {ump[req],i};
            }
            ump[arr[i]] = i;
        }
        return {-1,-1};
    }
};