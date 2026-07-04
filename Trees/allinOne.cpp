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

vector<vector<int>> traversal(TreeNode* root){
    vector<int> inorder;
    vector<int> preorder;
    vector<int> post;

    stack<pair<TreeNode*,int>> st;

    st.push({root,1});

    while(!st.empty()){
        pair<TreeNode*,int> p = st.top();

        if(p.second == 1){
            preorder.push_back(p.first->data);
            st.pop();
            st.push({p.first,p.second+1});
            if(p.first->left){
                st.push({p.first->left,1});
            }
        }
        else if(p.second == 2){
            inorder.push_back(p.first->data);
            st.pop();
            st.push({p.first,p.second+1});
            if(p.first->right){
                st.push({p.first->right,1});
            }
        }
        else{
            post.push_back(p.first->data);
            st.pop();
        }
    }

    vector<vector<int>> ans;

    ans.push_back(preorder);
    ans.push_back(inorder);
    ans.push_back(post);
    return ans;
}

int main()
{
    // Creating a sample binary tree
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    
    // Getting the pre-order, in-order,
    // and post-order traversals
    vector<int> pre, in, post;
    vector<vector<int>> traversals = traversal(root);

    // Extracting the traversals
    // from the result
    pre = traversals[0];
    in = traversals[1];
    post = traversals[2];

    // Printing the traversals
    cout << "Preorder traversal: ";
    for (int val : pre) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Inorder traversal: ";
    for (int val : in) {
        cout << val << " ";
    }
    cout << endl;

    cout << "Postorder traversal: ";
    for (int val : post) {
        cout << val << " ";
    }
    cout << endl;

    return 0;
}