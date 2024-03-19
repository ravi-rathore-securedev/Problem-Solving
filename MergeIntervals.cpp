#include<bits/stdc++.h>
using namespace std;
//Merge the overlapping intervals if possible         


vector<vector<int>> mergeIntervals(vector<vector <int>> a,int n){
   if (a.empty()) return {};
    
    sort(a.begin(), a.end());
    
    int start = a[0][0];
    int end = a[0][1];
    
    vector<vector<int>> ans;
    
    for (int i = 1; i < a.size(); ++i) {
        if (a[i][0] <= end) {
            end = max(end, a[i][1]);
        } else {
            ans.push_back({start, end});
            start = a[i][0];
            end = a[i][1];
        }
    }
    
    ans.push_back({start, end});
    
    return ans;
}


int main(){
int n;
cout<<"Enter the size of array: ";
cin>>n;

  vector<vector<int>> arr(n, vector<int>(2));

for(auto  &i:arr){
    for(auto & el:i){
        cin>>el;
    }
}

vector<vector<int>> ans=mergeIntervals(arr,n);


for(auto & i:ans){
    for(auto & el:i){
        cout<<el<<" ";
    }
    cout<<"\n";
}


return 0;
 }