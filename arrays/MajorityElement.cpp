#include<bits/stdc++.h>
using namespace std;

//FIXME: Find the element that occured more than n/2 times  


// TODO: 3. Optimal Approach
// Moore's Voting Method
int majorityByOptimal(int a[],int n){
    int cnt=0;
    int elem;
    for(int i=0;i<n;i++){
        if(cnt==0){
            cnt=1;
            elem=a[i];
        }
        else if(a[i]==elem) cnt++;
        else cnt--;
    }
    int cnt1 = 0;
    for (int i = 0; i < n; i++) {
        if (a[i] == elem) cnt1++;
    }
    if (cnt1 > (n / 2)) return elem;
    return -1;
}




//TODO: 2. Better approach
//using Hashmap
int majorityByMap(int arr[],int n){
    map <int,int> mapp;

    for(int i=0;i<n;i++){
        mapp[arr[i]]++;
    }
    for(auto i:mapp){
        if(i.second>(n/2))
        return i.first;
    }
    return -1;
}


//TODO: 1. Brute approach
// counting elements occurence and checking 
int majority(int a[],int n){
    for(int i=0;i<n;i++){
        int cnt=0;
        int elem=a[i];
        for(int j=0;j<n;j++){
            if(a[j]==elem) cnt++;
        }
        if(cnt>(n/2))
        return a[i];
    }
    return -1;
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

    // int ans= majority(arr,n);
    // int ans= majorityByMap(arr,n);
    int ans= majorityByOptimal(arr,n);
    
    cout<<"The answer is: "<<ans;
return 0;
 }