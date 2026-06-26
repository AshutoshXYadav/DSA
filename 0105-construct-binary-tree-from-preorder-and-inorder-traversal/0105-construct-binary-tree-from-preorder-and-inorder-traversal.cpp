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
    TreeNode* bt(vector<int>& preorder, int prestart, int preend, 
                 vector<int>& inorder, int instart, int inend, 
                 map<int, int>& inMap) {
        
       
        if (prestart > preend || instart > inend) {
            return nullptr; }
        
        TreeNode* root = new TreeNode(preorder[prestart]);
        
        int i = inMap[preorder[prestart]];
        int numLeft = i - instart; 

       
        root->left = bt(preorder, prestart + 1, prestart + numLeft, inorder, instart, i - 1, inMap);
        root->right = bt(preorder, prestart + numLeft + 1, preend, inorder, i + 1, inend, inMap);

        return root; }

    TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
        map<int, int> inMap;
        for (int i = 0; i < inorder.size(); i++) {
            inMap[inorder[i]] = i;
        } 
        
        return bt(preorder, 0, preorder.size() - 1, inorder, 0, inorder.size() - 1, inMap);
    }
};