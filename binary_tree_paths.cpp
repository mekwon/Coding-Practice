/**
 * Given a binary tree, return all root-to-leaf paths.

 * For example, given the following binary tree:
        1
      /   \
     2     3
      \
       5
   All root-->leaf paths are 
   ["1->2->5", "1->3"]
   
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
    vector<string> binaryTreePaths(TreeNode* root) 
    {
        vector<string> path;
        
        // If empty input
        if (!root)
            return path;
        
        // Else, do a dfs on tree and find every path
        dfs(root, to_string(root->val), path);
        return path;
    }
    
    void dfs(TreeNode* root, string value, vector<string>& path) 
    {
        // Path has ended, push back entire string
        if (!(root->left) && !(root->right)) 
            path.push_back(value);
        
        if (root->left)
            dfs(root->left, value + "->" + to_string(root->left->val), path);
        
        if (root->right)
            dfs(root->right, value + "->" + to_string(root->right->val), path);
    }
    
};