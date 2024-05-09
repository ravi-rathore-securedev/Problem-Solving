#include<bits/stdc++.h>
using namespace std;
//FIXME: find the triplets from array whose sum is 0

//optimal approach
//using pointer approach
//TC: O(N*N)
vector<vector<int>> threeSumPointer(vector<int>a,int n){
    vector<vector<int>>ans;
    
    sort(a.begin(),a.end());

    for(int i=0;i<n;i++){
        if(i!=0&&a[i]==a[i-1])continue;

        int left=i+1;
        int right=n-1;
        while(left<right){
            int sum=a[i]+a[left]+a[right];
            if(sum<0)   left++;

            else if(sum>0) right--;

            else    {
                vector<int>temp={a[i],a[left],a[right]};
                ans.push_back(temp);
                left++;
                right--;
                while(left<right && a[left]==a[left-1]) left++;
                while(left<right && a[right]==a[right+1]) right--;
            }

        }
    }
    return ans;
}




//Better approach
//TC:O(N*N*logN)
vector<vector<int>> threeSumByHash(vector<int>a,int n){
   set<vector<int>> st;
   
   for(int i=0;i<n;i++){
    set<int> hashset;
    for(int j=i+1;j<n;j++){
        int third=-(a[i]+a[j]);
        if(hashset.find(third)!=hashset.end()){
            vector<int> temp={a[i],a[j],third};
            sort(temp.begin(),temp.end());
            st.insert(temp);
        }
        hashset.insert(a[j]);
    }
   }
   vector<vector<int>> ans(st.begin(),st.end());
   return ans;
}



//Brute force approach
//TC:O(N**3)
vector<vector<int>> threeSum(vector<int>a,int n){
    set<vector<int>>ans;
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                if(a[i]+a[j]+a[k]==0){
                    vector<int>temp={a[i],a[j],a[k]};
                    sort(temp.begin(),temp.end());
                    ans.insert(temp);
                }

            }
        }
    }
    vector<vector<int>> final(ans.begin(),ans.end());
    return final;
}


int main(){

    int n;
    cout<<"Enter the size of array: ";
    cin>>n;
    vector<int>a(n);
    cout<<"Enter the values of array "<<endl;
    for(auto &i:a){
        cin>>i;
    }
    // vector<vector<int>>ans=threeSum(a,n);
    // vector<vector<int>>ans=threeSumByHash(a,n);
    vector<vector<int>>ans=threeSumPointer(a,n);

    for(auto i:ans){
        for(auto it:i){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
return 0;
 }