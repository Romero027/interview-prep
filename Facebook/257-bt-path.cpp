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
    vector<string> binaryTreePaths(TreeNode* root) {
        vector<string> res = {};
        if( !root ) return res;
        deque<pair<TreeNode*, string>> dq;
        dq.push_back(make_pair(root, ""));
        while( !dq.empty() ) {
            pair<TreeNode*, string> temp = dq.back();
            dq.pop_back();
            if( !temp.first->left && !temp.first->right )
                res.push_back( temp.second + to_string(temp.first->val));
            if(temp.first->left)
                dq.push_back(make_pair(temp.first->left, temp.second + to_string(temp.first->val)+ "->"));
            if(temp.first->right)
                dq.push_back(make_pair(temp.first->right, temp.second + to_string(temp.first->val)+ "->"));
        }
        return res;
    }
};