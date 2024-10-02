//approch 1
class Solution {
public:
    TreeNode *prev;
    void flatten(TreeNode* root) {
       prev=NULL;
       fun(root);
    }
    void fun(TreeNode* root){
        if(root==NULL) return;
        fun(root->right);
        fun(root->left);
        root->right = prev;
        root->left = NULL;
        prev = root;
    }
};
//approch 2: threaded binary tree

class Solution {
public:
    void flatten(TreeNode* root) {
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left==NULL){
                cur  = cur->right;
            }else{
                TreeNode* prev = cur->left;
                while(prev->right!=NULL){
                    prev = prev->right;
                }
                prev->right = cur->right;
                cur->right = cur->left;
                cur->left = NULL;
                cur=cur->right;
            }
        }
    }
};