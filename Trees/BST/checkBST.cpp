class Solution {
public:
    bool fun(TreeNode *root,long l,long r){
        if(!root) return true;
        // cout<<root->val<<" "<<l<<" "<<r<<endl;
        if(root->val<=l || root->val>=r) return false;
        return fun(root->left,l,root->val) && fun(root->right,root->val,r);
    }
    bool isValidBST(TreeNode* root) {
        
        return fun(root,LONG_MIN,LONG_MAX);
    }
};