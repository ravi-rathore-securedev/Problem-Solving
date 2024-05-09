#include<bits/stdc++.h>
using namespace std;
// count the no. of subarray having Xor of elements is k

//optimal Approach
int SubArrayXorMap(vector<int> a,int n, int k){
    int xr=0;

    map<int,int> mpp;
    mpp[xr]++;
    int cnt=0;
    for(int i=0;i<n;i++){
        xr=xr^a[i];

        int x=xr^k;
        cnt+=mpp[x];

        mpp[xr]++;

    }
    return cnt;
}



//Better Brute approach
int SubArrayXor(vector<int> a,int n, int k){
    int cnt=0;
    for(int i=0;i<n;i++){
    int xr=0;
    for(int j=i;j<n;j++){
        xr=xr^a[j];
        if(xr==k){
            cnt++;
        }
    }    
    }
    return cnt;
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
int k;
cout<<"Enter the element for XOR: ";
cin>>k;
    // int ans=SubArrayXor(a,n,k);
    int ans=SubArrayXorMap(a,n,k);
    
cout<<"The answer is: "<<ans;
return 0;
 }