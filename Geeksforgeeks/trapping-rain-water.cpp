//first method
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int total_water = 0;
        
        for(int i=1;i<n-1;i++){
            int lb = *max_element(height.begin(),height.begin()+i+1);
            int rb = *max_element(height.begin()+i,height.end());
            total_water += (min(lb,rb)-height[i]);
        }
        return total_water;
    }
};

// second method
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        vector<int> left(n,0);
        vector<int> right(n,0);
        
        left[0] = height[0];
        for(int i=1;i<n;i++)
            left[i] = max(left[i-1],height[i]);
        
        right[n-1] = height[n-1];
        for(int i=n-2;i>=0;i--)
            right[i] = max(right[i+1],height[i]);
        
        int total_water = 0;
        for(int i=1;i<n-1;i++)
            total_water += (min(left[i],right[i])-height[i]);
        
        return total_water;
    }
};

// third method
class Solution {
public:
    int trap(vector<int>& height) {
        int n = height.size();
        int left_mx = INT_MIN;
        int right_mx = INT_MIN;
        
        int left = 0;
        int right = n-1;
        int total_water = 0;
        
        while(left<right){
            if(height[left]<height[right]){
                if(height[left]>left_mx)
                    left_mx = height[left];
                else
                    total_water += (left_mx-height[left]);
                left++;
            }
            else{
                if(height[right]>right_mx)
                    right_mx = height[right];
                else
                    total_water += (right_mx-height[right]);
                right--;
            }
        }
        return total_water;
    }
};