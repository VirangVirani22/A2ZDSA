class Solution {
public:
    int ans;
    int fun(TreeNode* root){
        if(root==NULL) return 0;
        int l = max(0,fun(root->left));  //important max(0,....)
        int r = max(0,fun(root->right));
        ans  = max(ans,root->val+l+r);
        return root->val+max(l,r);
    }
    int maxPathSum(TreeNode* root) {
        ans=INT_MIN;
        fun(root);
        return ans;
    }
};