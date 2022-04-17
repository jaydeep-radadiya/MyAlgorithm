// tc : O(n) sc : O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        
        for(int i=1;i<n-1;i++){
            if(arr[i]>arr[i-1] && arr[i]>arr[i+1]){
                return i;
            }
        }
        return -1;
    }
};

// tc : O(n) sc : O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int max_idx = max_element(arr.begin(),arr.end())-arr.begin();
        return max_idx;
    }
};

// tc : O(logn) sc : O(1)
class Solution {
public:
    int peakIndexInMountainArray(vector<int>& arr) {
        int n = arr.size();
        int left = 0;
        int right = n-1;
        
        while(left<right){
            int mid = left+(right-left)/2;
            
            if(arr[mid]>arr[mid+1])
                right = mid; // we don't want to loose our answer
            else
                left = mid+1;
        }
        return left;
    }
};