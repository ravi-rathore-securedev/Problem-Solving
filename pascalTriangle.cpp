#include<bits/stdc++.h>
using namespace std;

//give me the row and column to print the value on that index in pascal triangle
int PascalValue(int n,int r){
    int row=n-1;
    int col=r-1;
    int ans=1;
    for(int i=0;i<col;i++){
        ans=ans*(row-i);
        ans=ans/(i+1);
    }
    return ans;
}


//print any one row of pascal triangle
    vector<int>printRow(int row){
        vector<int>ansRow;
        int ans=1;
        ansRow.push_back(1);
        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }





//Print the pascal triangle till the nth row
    vector<int>generateRow(int row){
        long ans=1;
        vector<int>ansRow;
        ansRow.push_back(1);

        for(int i=1;i<row;i++){
            ans=ans*(row-i);
            ans=ans/i;
            ansRow.push_back(ans);
        }
        return ansRow;
    }
vector<vector<int>> generatePascalTriangle(int rows){
    vector<vector<int>> ans;
    for(int i=1;i<=rows;i++){
        ans.push_back(generateRow(i));
    }
    return ans;
}
          
          
int main(){
int n;
// cout<<"How many rows you want to print in pascal triangle: ";
// cout<<"Enter the row you want to print of pascal triangle: ";
cout<<"Enter the row of pascal triangle: ";
cin>>n;
int t;
cout<<"Enter the column of pascal triangle: ";
cin>>t;

int ans=PascalValue(n,t);
cout<<"the answer is "<<ans;


// vector<int> ans=printRow(n);
// for(auto i:ans){
//     cout<<i<<" ";
// }

// vector<vector<int>> ans=generatePascalTriangle(n);
//  for (auto it : ans) {
//         for (auto ele : it) {
//             cout << ele << " ";
//         }
//         cout << "\n";
//     }
return 0;
 }