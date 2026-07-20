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

    auto getRootElementIndex(vector<int>& inorder, int ele){
        for(auto it = inorder.begin(); it != inorder.end(); it++){
            if(*it == ele){
                return it;
            }
        }

        return inorder.end();
    }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        if(!preorder.size() || !inorder.size()) return nullptr;
        
        TreeNode* root = new TreeNode(preorder[0]);
        auto rootIdx = getRootElementIndex(inorder, preorder[0]);

        vector<int> leftInorder(inorder.begin(), rootIdx);
        vector<int> rightInorder(rootIdx + 1, inorder.end());

        int subTreeSize = rootIdx - inorder.begin();

        vector<int> leftPreorder(preorder.begin() + 1, preorder.begin() + 1 + subTreeSize);
        vector<int> rightPreorder(preorder.begin() + 1 + subTreeSize, preorder.end());

        root->left = buildTree(leftPreorder, leftInorder);
        root->right = buildTree(rightPreorder, rightInorder);

        return root;
    }
};
