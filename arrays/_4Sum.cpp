#include<bits/stdc++.h>
using namespace std;
//

vector<vector<int>> fourSumOptimal(vector<int>a,int n,int target){
        vector<vector<int>>ans;
        sort(a.begin(),a.end());
        for(int i=0;i<n;i++){
            if(i!=0 && a[i]==a[i-1]) continue;
        for(int j=i+1;j<n;j++){
            if(j!=i+1 && a[j]==a[j-1]) continue;
            int k=j+1;
            int l=n-1;

            while(k<l){
            long long sum=a[i]+a[j];
            sum+=a[k];
            sum+=a[l];
            if(sum==target){
                vector<int>temp={a[i],a[j],a[k],a[l]};
                ans.push_back(temp);
                k++;
                l--;
                while(k<l && a[k]==a[k-1])k++;
                while(k<l && a[l]==a[l+1])l--;
            }
            else if(sum<target) k++;
            else l--;
            }
        }
        }
        return ans;
}


vector<vector<int>> fourSumBetter(vector<int>a,int n,int target){
     set<vector<int>> ls;
     
    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            set<long long>hashset;
            for(int k=j+1;k<n;k++){
                long long forth=(a[i]+a[j]+a[k]);
                long long sum=target-forth;
                if(hashset.find(sum)!=hashset.end()){
                    vector<int>temp={a[i],a[j],a[k],(int) (sum)};
                    sort(temp.begin(),temp.end());
                    ls.insert(temp);
                }
                hashset.insert(a[k]);
            }
        }
    }

      vector<vector<int>> ans(ls.begin(),ls.end());
    return ans;
}





vector<vector<int>> fourSum(vector<int>a,int n,int target){
    set<vector<int>> ls;

    for(int i=0;i<n;i++){
        for(int j=i+1;j<n;j++){
            for(int k=j+1;k<n;k++){
                for(int l=k+1;l<n;l++){
                    int sum=a[i]+a[j];
                    sum+=a[k];
                    sum+=a[l];
                    if(sum==target){
                        vector<int> temp={a[i],a[j],a[k],a[l]};
                        sort(temp.begin(),temp.end());
                        ls.insert(temp);
                    }
                }
            }
        }
    }
    vector<vector<int>> ans(ls.begin(),ls.end());
    return ans;
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
    int k;
      cout<<"Enter the target: ";
    cin>>k;
    // vector<vector<int>>ans=fourSum(a,n,k);
    // vector<vector<int>>ans=fourSumBetter(a,n,k);
    vector<vector<int>>ans=fourSumOptimal(a,n,k);

    for(auto i:ans){
        for(auto it:i){
            cout<<it<<" ";
        }
        cout<<"\n";
    }
return 0;
 }