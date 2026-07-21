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
    pair<int, int> dfs(TreeNode* root){
        if(!root){
            return {0, 0};
        }

        auto [LRob, LNotRob] = dfs(root->left);
        auto [RRob, RNotRob] = dfs(root->right);

        int robThis = root->val + LNotRob + RNotRob;

        int skipThis = max(LRob, LNotRob) + max(RRob, RNotRob);

        return {robThis, skipThis};
    }
    

    int rob(TreeNode* root) {
        auto [rob, notRob] = dfs(root);

        return max(rob, notRob);
    }
};