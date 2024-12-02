class Solution {
public:
    TreeNode *first = NULL, *second = NULL;
    TreeNode *prev = new TreeNode(INT_MIN);
    void inorder(TreeNode *root){
        if(root==NULL) return;
        inorder(root->left);
        if(prev->val>root->val) {
            if(first==NULL){
                first = prev;
            }
            if(first!=NULL){
                second = root;
            }
        }
        prev = root;
        inorder(root->right);
    }
    void recoverTree(TreeNode* root) {
        inorder(root);
        swap(first->val,second->val);
    }
};