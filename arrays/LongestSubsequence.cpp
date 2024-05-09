#include<bits/stdc++.h>
using namespace std;

//FIXME:Find the longest sequence in array
// [1,2,2,3,4,100,101,101,102,3] =>  ans=4         

//TODO: approach:store in set DS and find the previous consecutie in set
//TC:O(N)+O(2N) =O(3N)
//SC:O(N)
int LongConsSequenceBySet(vector <int> a, int n){
    unordered_set<int> sett;
    int longest=1;

    for(int i=0;i<n;i++){
        sett.insert(a[i]);
    }

    for(auto it:sett){
        if(sett.find(it-1)==sett.end()){
            int cnt=1;
            int x=it;
        while(sett.find(x+1)!=sett.end()){
            x++;
            cnt++;
        }

        longest= max(longest,cnt);
    }
    }
    return longest;
}


//TODO:approach:sort the array and find the consecutive  //Better Approach
//TC:O(N*logN)+O(N)
//SC:O(1)
int LongConsecutiveSequence(vector <int> a, int n){
    sort(a.begin(),a.end());
    int lastSmaller=INT_MIN;
    int currCnt=0;
    int longest=1;
    for(int i=0;i<n;i++){
        if(a[i]-1==lastSmaller){
            currCnt++;
            lastSmaller=a[i];
        }
        else if(lastSmaller!=a[i]){
            currCnt=1;
            lastSmaller=a[i];
        }
        longest=max(longest,currCnt);
    }
    return longest;
}


//TODO: 1. Brute force approach
//approach : pick index element and find next consecutive in array and count all consecutive
bool linearSearch(vector<int>&a,int nums){
    int n=a.size();
    for(int i=0;i<n;i++){
        if(a[i]==nums) return true;
    }
    return false;
}
// TC: O(N*N)
//SC:O(1)
int LongConsSequence(vector <int> a, int n){
    int longest=1;
    for(int i=0;i<n;i++){
       int x=a[i];
       int cnt=1;
       while(linearSearch(a,x+1)==true){
        x+=1;
        cnt++;
       }
       longest=max(longest,cnt);
    }
    return longest;
}       
          
int main(){
int n;
cout<<"Enter the size of Array: ";
cin>>n;
vector<int> a(n);
cout<<"Enter the elements in array"<<endl;
for(int i=0;i<n;i++){
    cin>>a[i];
}

// int ans=LongConsSequence(a,n);
// int ans=LongConsecutiveSequence(a,n);
int ans=LongConsSequenceBySet(a,n);

cout<<"The length of longest Sequence of array is "<<ans;

return 0;
 }