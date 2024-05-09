#include<bits/stdc++.h>
using namespace std;
//FIXME:Rearrange Elements by sign in such a way that order remain unchanged 

//not having equal positive and negative values
void RearrElementsAll(vector<int> &a,int n ){
    vector<int> pos,neg;
    for(int i=0;i<n;i++){
        if(a[i]>0) pos.push_back(a[i]);
        else neg.push_back(a[i]);
    }
    if(pos.size()>neg.size()){
        for(int i=0;i<neg.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=neg.size();
        for(int i=2*index;i<pos.size();i++){
            a[i]=pos[index];
            index++;
        }
    }
    else {
         for(int i=0;i<pos.size();i++){
            a[2*i]=pos[i];
            a[2*i+1]=neg[i];
        }
        int index=pos.size();
        for(int i=2*index;i<neg.size();i++){
            a[i]=neg[index];
            index++;
        }
    }
}




//optimal Approach
vector<int> RearrElementsOptimal(vector<int> &a,int n ){
    vector<int> ans(n,0);
    int pos=0,neg=1;
        for(int i=0;i<n;i++){
            if(a[i]>0){
                ans[pos]=a[i];
                pos+=2;
            }
            else{
                ans[neg]=a[i];
                neg+=2;
            }
        }
        return ans;
    

}




//this is for having equal number of positives and negatives
//TODO:1:Brute Approach
void RearrElements(vector<int> &a,int n ){
    vector<int> pos,neg;
 for(int i=0;i<n;i++){
 if(a[i]>0) pos.push_back(a[i]);
 else if(a[i]<0) neg.push_back(a[i]);
 }
for(int i=0;i<n/2;i++){
    a[2*i]=pos[i];
    a[2*i+1]=neg[i];
}
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
//    RearrElements(a,n);
//    vector <int> ans=RearrElementsOptimal(a,n);
    RearrElementsAll(a,n);
    
    //  cout << "Rearranged array: ";
    // for (int i = 0; i < n; i++) {
    //     cout << ans[i] << " ";
    // }
    // cout << endl;
    cout << "Rearranged array: ";
    for (int i = 0; i < n; i++) {
        cout << a[i] << " ";
    }
    cout << endl;


return 0;
 }