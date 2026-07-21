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

    // pair<int, TreeNode*> dfs(TreeNode* root, int target){
    //     if(!root){
    //         return {-1, nullptr};
    //     }

    //     auto [leftVal, leftRef] = dfs(root->left, target);
    //     auto [rightVal, rightRef] = dfs(root->right, target);


    //     //check if curr node is leaf or can become a leaf
    //     if(root->val == target && !leftRef && !rightRef){
    //         int val = root->val;
    //         delete root;
    //         return {val, nullptr};
    //     }

    //     root->left = leftRef;
    //     root->right = rightRef;

    //     return {root->val, root};
    // }

    TreeNode* removeLeafNodes(TreeNode* root, int target) {
        if(!root){
            return nullptr;
        }

        TreeNode* left = removeLeafNodes(root->left, target);
        TreeNode* right = removeLeafNodes(root->right, target);

        if(root->val == target && !left && !right){
            delete root;
            return nullptr;
        }

        root->left = left;
        root->right = right;

        return root;
    }
};