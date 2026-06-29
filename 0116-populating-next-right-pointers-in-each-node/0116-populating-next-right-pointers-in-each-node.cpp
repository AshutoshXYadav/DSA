/*
// Definition for a Node.
class Node {
public:
    int val;
    Node* left;
    Node* right;
    Node* next;

    Node() : val(0), left(NULL), right(NULL), next(NULL) {}

    Node(int _val) : val(_val), left(NULL), right(NULL), next(NULL) {}

    Node(int _val, Node* _left, Node* _right, Node* _next)
        : val(_val), left(_left), right(_right), next(_next) {}
};
*/

class Solution {
public:
    Node* connect(Node* root) {
                if (root == NULL) return NULL;

        queue<Node*> st;
        st.push(root);
        while(!st.empty()){
           int sz = st.size();
           for(int i =0; i< sz; i++){
            Node* curr = st.front();
            st.pop();
            if(i<sz-1){
             curr->next = st.front();}
            if(curr->left != NULL){
            st.push(curr->left);

            }
            if(curr->right != NULL){
            st.push(curr->right);
 }
            }
           
            
           }
            return root;
        }
       
    
};