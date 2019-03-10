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
public:
    vector<vector<int>> verticalOrder(TreeNode* root) {
        vector<vector<int>> res;
        if( !root ) {
            return res;
        }
        
        unordered_map<int, vector<int>> dict;
        deque<pair<TreeNode*, int>> dq;
        
        dq.push_back(make_pair(root, 0));
        
        int max_ = 0, min_ = 0;
        
        while( !dq.empty() ) {
            pair<TreeNode*, int> temp = dq.front();
            dq.pop_front();

            dict[temp.second].push_back(temp.first->val);
            
            if( temp.first->left ) {
                dq.push_back(make_pair(temp.first->left, temp.second - 1));
                min_ = min(min_, temp.second - 1);
            }
            
            if( temp.first->right ) {
                dq.push_back(make_pair(temp.first->right, temp.second + 1));
                max_ = max(max_, temp.second + 1);
            }
        }
        
        for ( int i = min_; i <= max_; i++ ) {
            res.push_back(dict[i]);
        }
        return res;
    }
};