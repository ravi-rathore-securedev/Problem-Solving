#include<bits/stdc++.h>
using namespace std;
//FIXME: find the next permutation of an array
//[2,1,5,4,3,0,0] => [2,3,0,0,1,4,5]

//optimal Approach
//TC:O(3N)
//SC:O(1)
void nextPermutation(vector<int>&a,int n){
     int ind = -1;
    for (int i = n - 2; i >= 0; i--) {
        if (a[i] < a[i + 1]) {
            ind = i;
            break;
        }
    }
    if (ind == -1) {
        reverse(a.begin(), a.end());
        return;
    }
    for (int i = n - 1; i > ind; i--) {
        if (a[i] > a[ind]) {
            swap(a[i], a[ind]);
            break;
        }
    }
    reverse(a.begin() + ind + 1, a.end());
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

    //   sort01(arr);
    //   sort012(arr,n);
      nextPermutation(arr,n);

      cout << "Next permutation array: ";
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
return 0;
 }