#include<bits/stdc++.h>
using namespace std;
//find missing number from an array

//Function

//TODO: 2. using XOR method
int missingUsingXor(int a[],int n){
    int xor1=0,xor2=0;
    for(int i=1;i<=n;i++){
        xor1=xor1^i;
    }
    for(int i=0;i<n;i++){
        xor2=xor2^a[i];
    }
    return xor1^xor2;
}



//TODO: 1 approach using mathematical computation
int missingNum(int a[], int m){
    int n=m+1;
    int s=n*(n+1)/2;
    int sum = 0;
    for(int i=0;i<m;i++){
        sum+=a[i];
    }
    return s-sum;
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
    // int ans=missingNum(ar,n);
    int ans=missingUsingXor(ar,n);

    cout<<"the answer is: "<<ans;
return 0;
 }