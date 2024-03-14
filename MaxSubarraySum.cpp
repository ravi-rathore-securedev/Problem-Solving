#include<bits/stdc++.h>
using namespace std;
//FIXME:find the subarray having elements sum is maximum       


//TODO: #. Optimal Approach
// Kadane's Algorithm
int MaxSubSumOptimal(vector<int> a, int n){
    int maxi =INT_MIN;
    int sum=0;
    for(int i=0;i<n;i++){
        sum+=a[i];
        maxi=max(maxi,sum);
        if(sum<0) sum=0;
    }
    return maxi;
}



//TODO: 2. Better Approach
int MaxSubSumBetter(vector <int> a,int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        int sum = 0;
        for (int j = i; j < n; j++) {
            sum += a[j];
            maxi = max(maxi, sum);
        }
    }
    return maxi;
}

//TODO: 1.Brute Approach
int MaxSubSum(vector <int> a,int n){
    int maxi = INT_MIN;
    for (int i = 0; i < n; i++) {
        for (int j = i; j < n; j++) {
        int sum = 0;
            for(int k=i;k<j;k++){

            sum += a[k];
            maxi = max(maxi, sum);
            }
        }
    }
    return maxi;
}
          
          
int main(){

int n;
cout<<"Enter the size of array:";
cin>>n;
vector <int> a(n);
cout<<"Enter the elements of array"<<endl;
for(int i=0;i<n;i++){
    cin>>a[i];
}
    // int ans=MaxSubSum(a,n);
    // int ans=MaxSubSumBetter(a,n);
    int ans=MaxSubSumOptimal(a,n);
    
cout<<"The answer is: "<<ans;
return 0;
 }