//o(n)

class Solution {
public:
    int kthSmallest(TreeNode* root, int &k) {
        if(root==NULL) return -1;
        k--;
        if(k==0) return root->val;
        int l = kthSmallest(root->left,k);
        int r = kthSmallest(root->right,k);
        if(l!=-1) return l;
        if(r!=-1) return r;
        return -1;
    }
};

//o(k)
class Solution {
public:
    void fun(TreeNode* root,int &k,int &ans){
        if(root==NULL) return;
        fun(root->left,k,ans);
        k--;
        if(k==0){
            ans = root->val;
            return;
        }
        fun(root->right,k,ans);
    }
    int kthSmallest(TreeNode* root, int &k) {
        int ans = -1;
        fun(root,k,ans);
        return ans;
    }
};