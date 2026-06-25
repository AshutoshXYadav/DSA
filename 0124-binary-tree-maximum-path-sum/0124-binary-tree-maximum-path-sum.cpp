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
private:
  int maxSumFunction(TreeNode* root, int& maxSum){
    if (root == NULL){
        return 0;
    }
     int leftGain = max(maxSumFunction(root->left, maxSum) , 0);
     int rightGain = max(maxSumFunction(root->right,maxSum),0);

     int nodeGain = root-> val+ leftGain+rightGain;
      
      maxSum = max(nodeGain ,maxSum);
      return root->val + max(leftGain,rightGain);

}
public:
    int maxPathSum(TreeNode* root) {
        int maxSum = INT_MIN;
        maxSumFunction(root,maxSum);
        return maxSum;
    }
};