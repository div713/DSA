#include <iostream>
#include <vector>
using namespace std;

// Define the TreeNode structure
class TreeNode {
    public:
    int data;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : data(x), left(nullptr), right(nullptr) {}
};

vector<int> inorder(TreeNode* root){
    vector<int> ans;

    stack<TreeNode*> st;

    while(true){
        if(root != NULL){
            st.push(root);
            root = root->left;
        }
        else{
            if(st.empty()){
                break;
            }
            TreeNode* cur = st.top();
            st.pop();
            ans.push_back(cur->data);

            root = cur->right;
        }
    }

    return ans;
}

int main() {
    // Creating a binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // Getting the inorder traversal
    vector<int> result = inorder(root);

    // Displaying the inorder traversal result
    cout << "Inorder Traversal: ";
    for (int val : result) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}
