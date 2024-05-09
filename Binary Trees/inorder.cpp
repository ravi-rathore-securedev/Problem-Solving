#include <iostream>
#include <vector>
using namespace std;

//defining the tree structure
struct node {
    int data;
    node* left;
    node* right;

    node(int val) : data(val), left(NULL), right(NULL) {}
};

//creating tree
node* createTree(vector<int> a) {
    if (a.size() < 11) return nullptr;
    node* root = new node(a[0]);
    root->left = new node(a[1]);
    root->right = new node(a[2]);
    root->left->left = new node(a[3]);
    root->left->right = new node(a[4]);
    root->right->left = new node(a[5]);
    root->right->right = new node(a[6]);
    root->left->left->left = new node(a[7]);
    root->left->right->right = new node(a[8]);
    root->right->left->left = new node(a[9]);
    root->right->right->right = new node(a[10]);

    return root;
}
//print the tree
void printTree(node* root, int level = 0) {
    if (root == NULL) return;
    printTree(root->right, level + 1);

    for (int i = 0; i < level; i++) {
        cout << "\t";
    }
    cout << root->data << endl;

    printTree(root->left, level + 1);
}

//implementing preorder action
void inOrder(node* root, vector<int>& a) {
    if (root == NULL) return;
    inOrder(root->left, a);
    a.push_back(root->data);
    inOrder(root->right, a);
}

//traversing tree for preorder 
vector<int> inorderTraverse(node* root) {
    vector<int> ans;
    inOrder(root, ans);
    return ans;
}



int main() {
    vector<int> arr;
    int n = 11;
    cout << "Enter array values: ";
    for (int i = 0; i < n; i++) {
        int val;
        cin >> val;
        arr.push_back(val);
    }
    node* root = createTree(arr);
     printTree(root);
    //storing preorder value
    vector<int> result = inorderTraverse(root);
//printing preorder value
    for (auto i : result) {
        cout << i << " ";
    }
    cout << endl;

    return 0;
}
