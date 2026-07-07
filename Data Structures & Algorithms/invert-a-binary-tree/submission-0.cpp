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


//postorder travel -> if for a node both left and right exist -> swap

class Solution {
public:

    void swapChildren(TreeNode* parent){
        if(!parent->left && !parent->right)
            return;
        
        TreeNode* temp = parent->right;
        parent->right = parent->left;
        parent->left = temp;

        return;
    }

    TreeNode* invertTree(TreeNode* root) {

        if(!root){
            return root;
        }

        queue<TreeNode*> q;
        q.push(root);

        while(!q.empty()){
            TreeNode* curr = q.front();
            q.pop();

            if(curr->left){
                q.push(curr->left);
            }

            if(curr->right){
                q.push(curr->right);
            }

            swapChildren(curr);
        }

        return root;
    }
};
