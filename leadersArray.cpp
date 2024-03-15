#include<bits/stdc++.h>
using namespace std;

//FIXME: find leaders in array  
//[10,22,12,3,0,6] => [22,12,6]   

//TODO:2. optimal appproach
//traversing from right
vector<int> leadersArrayOptimal(vector<int> a, int n) {
    vector <int> ans;
    int maxi=INT_MIN;
    for(int i=n-1;i>=0;i--){
        if(a[i]>maxi){
            ans.push_back(a[i]);
            maxi=max(maxi,a[i]);
        }
    }

    sort(ans.begin(),ans.end());
    return ans;
}



//TODO: Brute force approach
//traversing from left
vector<int> leadersArray(vector<int> a, int n) {
    vector<int> ans;
    for (int i = 0; i < n; i++) {
        bool leader = true;
        for (int j = i + 1; j < n; j++) {
            if (a[j] > a[i]) {
                leader = false;
                break;
            }
        }
        if (leader)
            ans.push_back(a[i]);
    }
    return ans;
}

int main() {
    int n;
    cout << "Enter the size of array: ";
    cin >> n;

    vector<int> a(n);
    cout << "Enter the elements of array" << endl;
    for (int i = 0; i < n; i++) {
        cin >> a[i];
    }

    // vector<int> ans = leadersArray(a, n);
    vector<int> ans = leadersArrayOptimal(a, n);

    cout << "Leaders array: ";
    cout<<"[";
    for (int i = 0; i < ans.size(); i++) {
        cout << ans[i] << ",";
    }
    cout <<"]"<< endl;

    return 0;
}
