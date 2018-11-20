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
    deque<TreeNode*> trees;
    void bfs(vector<vector<int>>& ans, int mode) {
        int n = trees.size();
        vector<int> tmp;
        if (n == 0)
            return;
        for(int i=0; i<n; i++) {
            TreeNode* front = trees.front();
            trees.pop_front();
            if( front->left != NULL )
                trees.push_back(front->left);
            if( front->right != NULL )
                trees.push_back(front->right);
            tmp.push_back(front->val);
        }
        if(mode%2)
            std::reverse(tmp.begin(), tmp.end());
        ans.push_back(tmp);
    }
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        
        if( root == NULL )
            return ans;
        trees.push_back(root);
        
        for(int i=0; trees.size(); i++ )
            bfs(ans, i);
        return ans;
    }
};
