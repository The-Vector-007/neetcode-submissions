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
    int maxSum = INT_MIN;

    int dfs(TreeNode* root){
        if(!root){
            return 0;
        }

        int leftMax = max(0, dfs(root->left));
        int rightMax = max(0, dfs(root->right));

        maxSum = max(maxSum, root->val + leftMax + rightMax);

        return root->val + max(leftMax, rightMax);
    }

    int maxPathSum(TreeNode* root) {
        if(!root){
            return 0;
        }

        dfs(root);

        return maxSum;
    }
};
