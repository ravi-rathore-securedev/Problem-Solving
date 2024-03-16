#include<bits/stdc++.h>
using namespace std;

//FIXME:We have 2D array set the row and column to 0 if there is a 0 in the array    

//TODO:Optimal Approach:instead of using 1D array we will asign in the smae 2D array itself
vector<vector<int>> setMatrixOptimal(vector<vector<int>>& arr, int n, int m) {
int col0=1;
for(int i=0;i<n;i++){
    for(int j=0;j<m;j++){
        if(arr[i][j]==0 ){
            arr[i][0]=0;

            if(j!=0)
            arr[0][j]=0;

        else 
        col0=0;
            
        }
        
    }
}

for(int i=1;i<n;i++){
    for(int j=1;j<m;j++){

        if(arr[i][j]!=0){

        if(arr[0][j]==0||arr[i][0]==0){
            arr[i][j]=0;
        }
    }
    }
}
if(arr[0][0]==0){

    for(int j=0;j<m;j++){
        arr[0][j]=0;
    }
}
if(col0==0){
    for(int i=0;i<n;i++){
        arr[i][0]=0;
    }
}
return arr;
}



//TODO: approach: maintaining 2 array 1D col and row to mark
//TC:O(2*N*M)
//SC:O(N+M)
vector<vector<int>> setMatrixBetter(vector<vector<int>>& arr, int n, int m) {
    int col[m]={0};
    int row[n]={0};

    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
            if(arr[i][j]==0){
                col[j]=1;
                row[i]=1;
            }
        }
    }
    for(int i=0;i<n;i++){
        for(int j=0;j<m;j++){
        if(col[j]||row[i]){
            arr[i][j]=0;
        }
    }
    }
    return arr;
}



//helper function for marking row and column
void markRow(vector<vector<int>>& arr, int row, int m) {
    for (int j = 0; j < m; j++) {
        if (arr[row][j] != 0)
            arr[row][j] = -1;
    }
}
void markCol(vector<vector<int>>& arr, int col, int n) {
    for (int i = 0; i < n; i++) {
        if (arr[i][col] != 0)
            arr[i][col] = -1;
    }
}
//TODO: 1. Brute force approach 
//finding 0 and marking relevent row and column and setting 0
//TC:O(N*M)*O(N+M)+O(N*M)
//SC:O(1)
vector<vector<int>> setMatrix(vector<vector<int>>& arr, int n, int m) {
    // vector<vector<int>> modifiedArr = arr;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == 0) {
                markRow(arr, i, m);
                markCol(arr, j, n);
            }
        }
    }

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if (arr[i][j] == -1) {
                arr[i][j] = 0;
            }
        }
    }

    return arr;
}

int main() {
    int n, m;
    cout << "Enter the size of 2D matrix:";
    cin >> n >> m;

    vector<vector<int>> arr(n, vector<int>(m));

    cout << "Enter the elements of array:" << endl;

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            cin >> arr[i][j];
        }
    }

    // vector<vector<int>> ans = setMatrix(arr, n, m);
    // vector<vector<int>> ans = setMatrixBetter(arr, n, m);
    vector<vector<int>> ans = setMatrixOptimal(arr, n, m);


    cout << "The Final matrix is:\n";
    for (auto& row : ans) {
        for (auto& element : row) {
            cout << element << " ";
        }
        cout << endl;
    }

    return 0;
}
