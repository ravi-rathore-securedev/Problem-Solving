#include<bits/stdc++.h>
using namespace std;

//FIXME: Find the Longest subarray with sum K
// [1,2,3,4,1,1,1,1,2,3]   n=10   k=3

//TODO: 3. optimal Approach
// 2 pointer approach
int longestSubarrayUsingPointer(int arr[],int k, int n){
    int i=0,j=0,sum=arr[0],len=0;
    while(i<n){

        while(j<=i && sum>k){
                sum=sum-arr[j];
                j++;
        }
        
            if(sum==k){
                len = max(len,i-j+1);
            }
            i++;

        if(i<n){
            sum = sum+arr[i];
        }
       
    }
    return len;
}






//TODO: 2 better approach
// using hashmap and storing sum on indexes and slicing array in x-k from start
int longestSubarrayByMap(int arr[],int k, int n){
    map <int,int> mapp;
    int sum=0,len=0;
    for(int i=0;i<n;i++){
        sum=sum+arr[i];
        if(sum==k){
            len=max(len,i+1);
        }
        int rem = sum-k;
       if(mapp.find(rem)!=mapp.end()){
            int maxl=i-mapp[rem];
            len=max(len,maxl);
       }

       if(mapp.find(sum)==mapp.end()){
        mapp[sum]=i;
               }
    }
    return len;
}


//TODO: 1. Brute Approach 
// traversing entire array and generating all subarrays
int longestSubarray(int arr[],int k, int n){
    int len=0;
    for(int i=0;i<n;i++){
            int s=0;
        for(int j=i;j<n;j++){
                s+=arr[j];
            if(s==k){
                    len=max(len,j-i+1);
                }
        }
    }
    return len; 
}
          

          
int main(){
    int n;
    cout<<"enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elemenst of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

    // int ans= longestSubarray(arr,k,n);
    // int ans= longestSubarrayByMap(arr,k,n);
    int ans= longestSubarrayUsingPointer(arr,k,n);

    cout<<"The answer is: "<<ans;

return 0;
 }