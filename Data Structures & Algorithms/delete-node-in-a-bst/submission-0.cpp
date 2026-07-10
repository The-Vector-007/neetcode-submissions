/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* deleteNode(TreeNode* root, int key) {
        
        if(!root){
            return nullptr;
        }

        if(key < root->val){
            root->left = deleteNode(root->left, key);
        }

        if(key > root->val){
            root->right = deleteNode(root->right, key);
        }

        if(key == root->val){
            if (!root->left)  { auto r = root->right; delete root; return r; }
            if (!root->right) { auto l = root->left;  delete root; return l; }

            // find in-order successor (smallest in right subtree)
            TreeNode* curr = root->right;
            while (curr->left) curr = curr->left;

            root->val = curr->val;                          // copy value up
            root->right = deleteNode(root->right, curr->val); // recursively delete it properly
            return root;
        }


        return root;
    }
};