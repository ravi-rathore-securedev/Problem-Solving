#include<bits/stdc++.h>
using namespace std;
//Frst Buy the stock and sell on maximum profit

int maxProfit(vector<int>a,int n){
    int mini=a[0];
    int profit=0;
    for(int i=0;i<n;i++){
        int cost = a[i]-mini;
        profit=max(profit,cost);
        mini=min(mini,a[i]);
    }
    return profit;
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
    int ans=maxProfit(a,n);
   
    
cout<<"The answer is: "<<ans;
return 0;
 }