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
    vector<int> preorderTraversal(TreeNode* root) {
        if(root == nullptr){
            return {};
        }

        vector<int> ans;

        stack<TreeNode*> s;

        s.push(root);

        while(!s.empty()){
            TreeNode* processNode = s.top();
            s.pop();

            //visit node
            ans.push_back(processNode->val);

            //push first process second
            if(processNode->right != nullptr)
                s.push(processNode->right);
            //push second process first;
            if(processNode->left!= nullptr)
                s.push(processNode->left);
        }

        return ans;
    }
};