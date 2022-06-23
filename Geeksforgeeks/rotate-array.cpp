#include<bits/stdc++.h>
using namespace std;

void reverse(vector<int> &arr,int left,int right){
    while(left<right){
        swap(arr[left++],arr[right--]);
    }
}

void rotate(vector<int> &arr,int k){
    int n = arr.size();
    if(k<0){
        k = abs(k)%n;
        reverse(arr,0,k-1); // reverse left part
        reverse(arr,k,n-1); // reverse right part
        reverse(arr,0,n-1); // reverse entire array
    }
    else{
        k = abs(k)%n;
        reverse(arr.begin(),arr.end());
        reverse(arr,0,k-1);
        reverse(arr,k,n-1);
    }
}

int main(){
    int n,k;
    cin>>n>>k;
    vector<int> arr(n);
    for(int i=0;i<n;i++)
        cin>>arr[i];
        
    rotate(arr,k);
    for(int ele : arr)
        cout<<ele<<" ";
        
    return 0;
}