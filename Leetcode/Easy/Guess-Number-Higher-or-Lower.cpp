// tc : O(n) sc : O(1)
class Solution {
public:
    int guessNumber(int n) {
        for(int i=1;i<=n;i++){
            if(guess(i)==0) return i;
        }
        return -1;
    }
};

// tc : O(log2n) sc : O(1)
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left<=right){
            int mid = left+(right-left)/2;
            int ans = guess(mid);
            
            if(ans==0) return mid;
            else if(ans==-1) right = mid-1;
            else if(ans==1) left = mid+1;
        }
        return -1;
    }
};

// tc : O(log3n) sc : O(1)
class Solution {
public:
    int guessNumber(int n) {
        int left = 1;
        int right = n;
        
        while(left<=right){
            int m1 = left+(right-left)/3;
            int m2 = right-(right-left)/3;
            int r1 = guess(m1);
            int r2 = guess(m2);
            
            if(r1==0) return m1;
            else if(r2==0) return m2;
            else if(r1<0) right = m1-1;
            else if(r2>0) left = m2+1;
            else{
                left = m1+1;
                right = m2-1;
            }
        }
        return -1;
    }
};