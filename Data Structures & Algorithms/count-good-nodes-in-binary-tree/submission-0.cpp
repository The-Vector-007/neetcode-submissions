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
    int count = 0;

    void countGoodNodes(TreeNode* curr, int max_so_far){
        if(!curr){
            return;
        }

        if(curr->val >= max_so_far){
            count++;
            max_so_far = curr->val; //updated max_so_far
        }

        countGoodNodes(curr->left, max_so_far);
        countGoodNodes(curr->right, max_so_far);

        return;
    }

    int goodNodes(TreeNode* root) {
        int max_so_far = INT_MIN;

        countGoodNodes(root, max_so_far);

        return count;
    }
};
