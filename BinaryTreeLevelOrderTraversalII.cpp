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
    deque<TreeNode*> q;
    vector<int> traverse() {
        vector<int> ans;
        if( q.empty() ) 
            return ans;
        int n = q.size();
        for(int i=0; i<n; i++) {
            ans.push_back(q.front()->val);
            if(q.front()->left)
                q.push_back(q.front()->left);
            if(q.front()->right)
                q.push_back(q.front()->right);
            q.pop_front();
        }
        return ans;
    }
public:
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        vector<vector<int>> ans;
        if( root == NULL )
            return ans;
        q.push_back(root);
        while( !q.empty())
            ans.push_back(traverse());
        reverse(ans.begin(), ans.end());
        return ans;
    }
};
