#include <iostream>
using namespace std;
// TreeNode structure
class TreeNode {
    public:
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

TreeNode* childrenSum(TreeNode* root){
    if(!root) return 0;

    if(!root->left && !root->right){
        return root;
    }

    if(!root->right){
        if(root->left->val < root->val){
            root->left->val = root->val;
        }

        TreeNode* l = childrenSum(root->left);
        root->val = l->val;
        return root;
    }

    if(!root->left){
        if(root->right->val < root->val){
            root->right->val = root->val;
        }

        TreeNode* r = childrenSum(root->right);
        root->val = r->val;
        return root;
    }

    if(root->left->val + root->right->val < root->val){
        root->left->val = root->val;
        root->right->val = root->val;
    }

    TreeNode* l = childrenSum(root->left);
    TreeNode* r = childrenSum(root->right);

    root->val = l->val + r->val;

    return root;
}




void inorderTraversal(TreeNode* root) {
    if (root == nullptr) {
        return;
    }
    inorderTraversal(root->left);
    cout << root->val << " ";
    inorderTraversal(root->right);
}

int main(){
    TreeNode* root = new TreeNode(50);
    root->left = new TreeNode(7);
    root->right = new TreeNode(2);
    root->left->left = new TreeNode(3);
    root->left->right = new TreeNode(5);
    root->right->left = new TreeNode(1);
    root->right->right = new TreeNode(30);
    

    cout << "Binary Tree before modification: ";
    inorderTraversal(root);
    cout << endl;

    TreeNode* ans= childrenSum(root);

    cout << "Binary Tree after Children Sum Property: " ;
    inorderTraversal(root);
    cout << endl;

    return 0;

}