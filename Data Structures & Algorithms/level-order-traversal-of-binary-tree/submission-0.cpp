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

    int heightOfTree(TreeNode* root){
        if(!root){
            return 0;
        }

        int left = heightOfTree(root->left);
        int right = heightOfTree(root->right);

        return 1 + max(left, right);
    }

    vector<vector<int>> levelOrder(TreeNode* root) {

        if(!root){
            return {};
        }

        int h = heightOfTree(root);

        vector<vector<int>> levels(h);

        queue<TreeNode*> q;
        q.push(root);
        int level = 0;

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                q.pop();

                levels[level].push_back(curr->val);

                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }

            level++;
        }

        return levels;
    }
};
