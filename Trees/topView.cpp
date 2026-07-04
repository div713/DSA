#include <iostream>
#include <vector>
#include <map>
using namespace std;

class TreeNode {
    public:
    int val;
    TreeNode* left;
    TreeNode* right;
    TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
};

class Solution {
    map<int,int> store;
    void vert(TreeNode* root, int row, int col){
        if(!root) return;

        if(store.find(col) == store.end()){
            store[col]= root->val;
        }

        vert(root->left,row+1,col-1);
        vert(root->right,row+1,col+1);
    }
public:
    vector<int> bottomView(TreeNode* root) {
        store.clear();

        vert(root,0,0);

        vector<int> ans;

        for(auto it : store){
            ans.push_back(it.second);
        }

        return ans;
    }
};

int main(){
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(10);
    root->left->left->right = new TreeNode(5);
    root->left->left->right->right = new TreeNode(6);
    root->right = new TreeNode(3);
    root->right->right = new TreeNode(10);
    root->right->left = new TreeNode(9);

    Solution sol;

    vector<int> ans = sol.bottomView(root);

    for(int i=0; i<ans.size(); i++){
        cout<<ans[i]<<" ";
    }
    cout<<endl;
    return 0;
}