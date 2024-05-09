#include<bits/stdc++.h>
using namespace std;
//FIXME: Merge 2 sorted array without using any extra space
//optimal approach
void swapIfGreater(vector<int>&a1,vector<int>&a2,int ind1,int ind2){
if(a1[ind1]>a2[ind2]){
    swap(a1[ind1],a2[ind2]);
}
}
void MergeArrOptimalgap(vector<int>&a1,vector<int>&a2,int n,int m){
    int gap=(n+m)/2 + (n+m)%2;
    while(gap>0){
    int i=0;
    int j=i+gap;
    while(j<(n+m)){
       if(i<n && j>=n){
        swapIfGreater(a1,a2,i,j-n);
       }
       else if(i>=n){
        swapIfGreater(a2,a2,i-n,j-n);
       }
       else{
        swapIfGreater(a1,a1,i,j);
       }
       i++;
       j++;
    }
    if(gap==1) break;

    gap=gap/2+gap%2;
    }
}

//better approach
void MergeArrBetter(vector<int>&a1,vector<int>&a2,int n,int m){
    int i=n-1;
    int j=0;
    while(a1[i]>a2[j]){
        swap(a1[i],a2[j]);
        i--;
        j++;
    }
    sort(a1.begin(),a1.end());
    sort(a2.begin(),a2.end());
}


//brute force approach
void MergeArr(vector<int>&a1,vector<int>&a2,int n,int m){
        int i=0,j=0,index=0;
        vector<int>c(n+m);
        while (i < n && j < m) {
        if (a1[i] <= a2[j]) {
            c[index++] = a1[i++];
        } else {
            c[index++] = a2[j++];
        }
    }

    while (i < n) {
        c[index++] = a1[i++];
    }

    while (j < m) {
        c[index++] = a2[j++];
    }
        for (int k = 0; k < n + m; k++) {
        if (k < n) {
            a1[k] = c[k];
        } else {
            a2[k - n] = c[k];
        }
    }
}

int main(){
int n,m;
cout<<"Enter the size of 1st array: ";
cin>>n;

vector<int> a1(n);
cout<<"Enter the elements of array"<<endl;
for(auto &it:a1){
    cin>>it;
}

cout<<"Enter the size of 1st array: ";
cin>>m;

vector<int> a2(m);
cout<<"Enter the elements of array"<<endl;
for(auto &it:a2){
    cin>>it;
}

// MergeArr(a1,a2,n,m);
// MergeArrBetter(a1,a2,n,m);
MergeArrOptimalgap(a1,a2,n,m);

for(auto it:a1){
    cout<<it<<" ";
}
cout<<'\n';
for(auto it:a2){
    cout<<it<<" ";
}

return 0;
 }