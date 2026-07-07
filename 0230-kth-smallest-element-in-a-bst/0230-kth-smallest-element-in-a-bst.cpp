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
    int kthSmallest(TreeNode* root, int k) {
         int cnt =0;
        stack<TreeNode*> st;
        st.push(root) ;
        while(root != nullptr ||!st.empty()){
            while( root != NULL){
                st.push(root);
              root= root->left;
            }
            
            root= st.top();
            st.pop();
            cnt++;
            if(cnt== k){
                return root->val;
            }
            root=root->right;
           
        }
        return -1;
    }
};