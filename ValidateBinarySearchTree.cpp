/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
    vector<int> arr;
public:
    void trans(TreeNode* root) {
        if(root == NULL)
            return;
        trans(root->left);
        arr.push_back(root->val);
        trans(root->right);
    }
    
    bool isValidBST(TreeNode* root) {
        if(root == NULL)
            return true;
        trans(root);
        if(arr.size() == 1)
            return true;
        
        for(int i=0; i<arr.size() - 1; i++) {
            if(arr[i] >= arr[i+1])
                return false;
        }
        
        return true;
    }
};
