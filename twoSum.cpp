#include<bits/stdc++.h>
using namespace std;
//FIXME:find the elements in array whose sum is equal to k


//TODO: 2 Better approach
// using hashmap method
vector <int> twoSumByMap(int arr[], int k, int n) {
    map <int,int> mapp;
    for(int i=0;i<n;i++){
        int rem=k-arr[i];
        if(mapp.find(rem)!=mapp.end()){
            return {mapp[rem],i};
        }
       mapp[arr[i]]=i;
    }
    return {-1,-1};
}

//TODO: 1.Brute approach
vector<int> twoSum(int arr[], int k, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; j++) {
            if (arr[i] + arr[j] == k) {
                ans.push_back(i);
                ans.push_back(j);
                return ans;
            }
        }
    }
    return { -1, -1 };
}
          
          
int main(){
    int n;
    cout<<"enter array size: ";
    cin>>n;
    int arr[n];
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }
    int k;
    cout<<"Enter the value of k: ";
    cin>>k;

//    vector <int> ans= twoSum(arr,k,n);
   vector <int> ans= twoSumByMap(arr,k,n);
    // vector <int> ans= longestSubarrayUsingPointer(arr,k,n);

     cout << "This is the answer [" << ans[0] << ", "<< ans[1] << "]" << endl;

return 0;
 }