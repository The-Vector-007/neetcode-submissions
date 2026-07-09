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

    bool isSameTree(TreeNode* p, TreeNode* q){
        if(p == nullptr && q == nullptr){
            return true;
        }

        if(p == nullptr || q == nullptr){
            return false;
        }

        if(p->val != q->val){
            return false;
        }

        return isSameTree(p->left, q->left) && isSameTree(p->right, q->right);
    }

    vector<TreeNode*> searchPrimaryTree(TreeNode* root, int val){
        if(root == nullptr){
            return {};
        }

        vector<TreeNode*> possibleRoots;

        queue<TreeNode*> q;

        q.push(root);

        while(!q.empty()){
            int sz = q.size();

            for(int i = 0; i < sz; i++){
                TreeNode* curr = q.front();
                q.pop();

                if(curr->val == val){
                    possibleRoots.push_back(curr);
                }
                
                if(curr->left) q.push(curr->left);
                if(curr->right) q.push(curr->right);
            }
        }

        return possibleRoots;
    }

    bool isSubtree(TreeNode* root, TreeNode* subRoot) {
        if(root == nullptr){
            return false;
        }

        if(subRoot == nullptr){
            return true;
        }

        auto possibleRoots = searchPrimaryTree(root, subRoot->val);

        if(possibleRoots.size() == 0){
            return false;
        }

        for(auto node : possibleRoots){
            if(isSameTree(node, subRoot)){
                return true;
            }
        }

        return false;
    }
};
