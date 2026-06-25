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
    vector<vector<int>> zigzagLevelOrder(TreeNode* root) {
        vector<vector<int>> ans;
        if (root == nullptr) {
            return ans;
        }
        queue<TreeNode*> q;
        q.push(root);
        int flag =0;
        while(!q.empty()){
            int size = q.size();
            vector<int> level;
            
              for(int i=0; i<size; i++){
                TreeNode* currNode = q.front();
                q.pop();
                if(currNode->left != NULL){
                q.push(currNode->left);
                }
                if(currNode->right != NULL){
                q.push(currNode->right);

                }
                
                level.push_back(currNode->val);
              }
              if(flag ==0){
                flag=1;
              }
              else{
                reverse(level.begin(), level.end());
                flag=0;
              }
            ans.push_back(level);
        }
        return ans;
    }
};