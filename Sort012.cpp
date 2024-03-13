#include<bits/stdc++.h>
using namespace std;
// FIXME:Sort an array containing 0s, 1s, 2s

//TODO: 3. Optimal Approch
//Dutch National Flag Algorithm
//using 3 pointers low, mid, high and sorting elements using pointers

void sortArray(vector<int>& arr, int n)
{
   int low=0,mid=0,high=n-1;
    
    while(mid<=high){
        if(arr[mid]==0){
            swap(arr[low],arr[mid]);
            mid++;
            low++;
        }
        else if(arr[mid]==1) mid++;

        else {
              swap(arr[mid], arr[high]);
            high--;
        }
    }

}


//TODO: 2. Better approach
// counting 0s 1s and 2s and storing them at the sort places
void sort012(vector <int>&arr,int n){
  int cn1=0,cn2=0,cn0=0;

    for(int i=0;i<arr.size();i++){
      if(arr[i]==0) cn0++;
      if(arr[i]==1) cn1++;
      else cn2++;
    }
    for(int i=0;i<cn0;i++){
        arr[i]=0;
    }
     for(int i=cn0;i<cn0+cn1;i++){
        arr[i]=1;
    }
     for(int i=cn0+cn1;i<arr.size();i++){
        arr[i]=2;
    }
}


//TODO: 1. Brute approach
//using sort STL method
void sort01(vector <int>&arr){
    sort(arr.begin(),arr.end());
}




int main(){
    int n;
    cout<<"enter array size: ";
    cin>>n;

   vector <int> arr(n);
    cout<<"enter the elements of array: "<<endl;
    for(int i=0;i<n;i++){
        cin>>arr[i];
    }

    //   sort01(arr);                         //function call
    //   sort012(arr,n);
      sortArray(arr,n);

      cout << "Sorted array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;

return 0;
 }