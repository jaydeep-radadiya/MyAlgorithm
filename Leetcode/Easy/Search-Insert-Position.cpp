// tc : O(n) sc : O(1)
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        for(int i=0;i<n;i++){
            if(arr[i]>=target){
                return i;
            }
        }
        return n; // never never forget this edge case
    }
};

// tc : O(logn) sc : O(1)
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int idx = lower_bound(arr.begin(),arr.end(),target)-arr.begin();
        return idx;
    }
};

// tc : O(logn) sc : O(1)
class Solution {
public:
    int searchInsert(vector<int>& arr, int target) {
        int n = arr.size();
        int left = 0;
        int right = n-1;

        while(left<=right){
            int mid = left+(right-left)/2;

            if(arr[mid]==target) return mid;
            else if(arr[mid]>target) right = mid-1;
            else if(arr[mid]<target) left = mid+1;
        }
        return left; // don't forget this 
    }
};