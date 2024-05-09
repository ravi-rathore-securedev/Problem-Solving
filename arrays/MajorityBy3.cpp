#include<bits/stdc++.h>
using namespace std;
//find the majority element which occured more than n/3 times

//TODO: optimal approach
    vector<int>MajorityOptimal(vector<int>a,int n){
       
        int cn1 = 0, cn2 = 0;
        int el1 = 0, el2 = 0;
        for (int i = 0; i < n; i++) {
            if (cn1 == 0 && (cn2 == 0 || el2 != a[i])) {
                cn1 = 1;
                el1 = a[i];
            } else if (cn2 == 0 && el1 != a[i]) {
                cn2 = 1;
                el2 = a[i];
            } else if (a[i] == el1) {
                cn1++;
            } else if (a[i] == el2) {
                cn2++;
            } else {
                cn1--;
                cn2--;
            }
        }
        
        cn1 = 0; cn2 = 0;
        vector<int> ans;
        for (int i = 0; i < n; i++) {
            if (a[i] == el1) cn1++;
            else if (a[i] == el2) cn2++;
        }
        
        int mini = n / 3;
        if (cn1 > mini) ans.push_back(el1);
        if (cn2 > mini) ans.push_back(el2);

        return ans;

    }


//TODO: 2. using hash map 
//Better approach
    vector<int>MajorityByMap(vector<int>a,int n){
        vector<int>ans;

        map<int,int>mpp;
        int mini=int(n/3)+1;

        for(int i=0;i<n;i++){
            mpp[a[i]]++;
            if(mpp[a[i]]==mini){
                ans.push_back(a[i]);
            }
            if(ans.size()==2) break;

        }
        return ans;

    }


//TODO: Brute force approach
vector<int> majority(vector <int> a,int n){
    vector<int> ans;
    for(int i=0;i<n;i++){
        if(ans.size()==0|| ans[0]!=a[i]){
            int cnt=0;
            for(int j=0;j<n;j++){
                if(a[j]==a[i]){
                    cnt++;
                }
            }
    if(cnt>(n/3)) ans.push_back(a[i]);
        }
        if(ans.size()==2) break;
    }
    return ans;
}
          
          


int main(){

int n;
cout<<"Enter the size of an array: ";
cin>>n;

vector<int> a(n);
cout<<"Enter the elements of an array"<<endl;

for(auto &i:a){
    cin>>i;
}

// vector<int> ans= majority(a,n);
// vector<int> ans= MajorityByMap(a,n);
vector<int> ans= MajorityOptimal(a,n);

for(auto i:ans){
    cout<<i<<" ";
}
return 0;
 }