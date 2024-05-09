#include<bits/stdc++.h>
using namespace std;
// Find the missing and repeat elements        

//using maths
   vector<int> MissAndRepeatByMath(vector<int> a, int n){
    int S=0,S2=0;
    int Sn=(n*(n+1))/2;
    int S2n=(n*(n+1)*(2*n+1))/6;

    for(int i=0;i<n;i++){
        S+=a[i];
        S2+=a[i]*a[i];
    }
    int val1=S-Sn;
    int val2=S2-S2n;
    val2=val2/val1;
    int repeat=(val1+val2)/2;
    int missing=(val2-val1)/2;

      return {repeat,missing};


   }


//better Apprach
   vector<int> MissAndRepeatByHash(vector<int> a, int n){
     int repeat=-1,missing=-1;
    int hasharr[n+1]={0};
    for(int i=0;i<n;i++){
        hasharr[a[i]]++;
    }
    for(int i=1;i<n+1;i++){
        if(hasharr[i]==2){
            repeat=i;
        }
        else if(hasharr[i]==0){
            missing=i;
        }
    }
    return {repeat,missing};
   }

//brute force approach
    vector<int> MissAndRepeat(vector<int> a, int n){
        int repeat=-1,missing=-1;
        for(int i=1;i<=n;i++){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[j]==i)
                    cnt++;
                
            }
            if(cnt==2) repeat=i;
            else if(cnt==0) missing=i;

            if(repeat!=-1 && missing!=-1)
            break;

    }
     return {repeat,missing};
    }

int main(){

    int n;
    cout<<"enter the size of array: ";
    cin>>n;

    vector<int> arr(n);
    cout<<"enter elements of array "<<endl;
    for(auto & i:arr){
        cin>>i;
    }

    // vector<int> ans=MissAndRepeat(arr,n);
    // vector<int> ans=MissAndRepeatByHash(arr,n);
    vector<int> ans=MissAndRepeatByMath(arr,n);

    cout<<"The answer are:";
       for(auto & i:ans){
        cout<<" "<<i;
    }
return 0;
 }