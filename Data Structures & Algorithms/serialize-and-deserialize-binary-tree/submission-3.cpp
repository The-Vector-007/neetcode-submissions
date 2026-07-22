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

class Codec {
public:


    string dfs(TreeNode* root){
        if(!root){
            return "N";
        }

        string left = dfs(root->left);
        string right = dfs(root->right);

        return to_string(root->val) + "," + left + "," + right;
    }

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string encodedString = dfs(root);
        cout << encodedString << endl;
        return encodedString;
    }

    TreeNode* dfs(vector<string>& data, int* i){
        if(data[*i] == "N"){
            (*i)++;
            return nullptr;
        }

        TreeNode* node = new TreeNode(stoi(data[*i]));
        (*i)++;
        node->left = dfs(data, i);
        node->right = dfs(data, i);
        return node;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string data) {
        if(!data.size()){
            return nullptr;
        }

        
        vector<string> ans;
        string curr = "";
        for(int i = 0; i < data.size(); i++){
            curr += data[i];
            if(data[i] == ','){
                curr.pop_back();
                ans.push_back(curr);
                curr = "";
            }
        }

        ans.push_back(curr);

        int i = 0;

        return dfs(ans, &i);
    }
};
