class Solution {
public:
    vector<TreeNode*> ans;
    unordered_set<int> to_del_set;

    TreeNode* helper(TreeNode* root, bool is_root) {
        if (!root) return nullptr;

        // Check if the current node needs to be deleted
        bool deleted = to_del_set.count(root->val);

        // If this is a standalone root and NOT deleted, it belongs in the final answer
        if (is_root && !deleted) {
            ans.push_back(root);
        }

        // Process children. 
        // If the current node is deleted, its children become potential new roots!
        root->left = helper(root->left, deleted);
        root->right = helper(root->right, deleted);

        // If this node was deleted, return nullptr to clear the parent's pointer
        return deleted ? nullptr : root;
    }

    vector<TreeNode*> delNodes(TreeNode* root, vector<int>& to_delete) {
        // Use an unordered_set for O(1) lookups instead of scanning a vector
        for (int val : to_delete) {
            to_del_set.insert(val);
        }
        
        // The original root is treated as a "root" initially
        helper(root, true);
        return ans;
    }
};