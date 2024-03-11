#include<bits/stdc++.h>
using namespace std;

// FIXME:find the number that appear once and rest twice


    int onceAppearByXOR(int a[],int n){
        int xorr=0;
        for(int i=0;i<n;i++){
            xorr=xorr^a[i];
        }
        return xorr;
    }


//TODO: 3. Better Approach using Map STL method
    int onceAppearByMap(int a[], int n){
        map <int,int>mapp;
        for(int i=0;i<n;i++){
            mapp[a[i]]++;
        }
        for(auto i:mapp){
            if(i.second==1){
                return i.first;
            }
        }
        return -1;

    }



//TODO: 2. better approach using hash array
int onceAppearByHash(int a[],int n){
    int maxi=0;
    for(int i=0;i<n;i++){
        maxi =max(maxi,a[i]);
    }
    int hash[maxi+1]={0};
    for(int i=0;i<n;i++){
        hash[a[i]]++;
    }
    for(int i=0;i<maxi+1;i++){
        if(hash[i]==1){
            return i;
        }
    }
         return -1;
}


// TODO: 1. Brute force approach
// taking 1 value and counting in the entire array
int onceAppear(int a[],int n){
    for(int i=0;i<n;i++){
        int nums=a[i];
        int count=0;
        for(int j=0;j<n;j++){
            if(a[j]==nums){
                count++;
            }
        }
        if(count==1){
            return a[i]; 
        }
    }
    return -1;
}


int main(){
    int n;
    cout<<"enter the number of elements in array: ";
    cin>>n;
   int ar[n];
    cout<<"enter the elements in array: ";
    for(int i=0;i<n;i++){
       cin>>ar[i];
    }
    // int ans=onceAppear(ar,n);
    // int ans=onceAppearByHash(ar,n);
    // int ans=onceAppearByMap(ar,n);
    int ans=onceAppearByXOR(ar,n);

    cout<<"the answer is: "<<ans;
}