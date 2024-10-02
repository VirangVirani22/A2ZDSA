class Solution {
public:
    vector<int> preorderTraversal(TreeNode* root) {
        vector <int> pre;
        TreeNode * cur = root;
        while(cur!=NULL){
            if(cur->left==NULL){
                pre.push_back(cur->val);
                cur = cur ->right;
            }else{
                TreeNode* last = cur->left;
                while(last->right!=NULL && last->right!=cur){
                    last = last->right;
                }
                if(last->right==NULL){
                     pre.push_back(cur->val);
                     last->right=cur;
                     cur = cur->left;
                }else{
                    last->right=NULL;
                    cur = cur->right;
                }
            }
        }
        return pre;
    }
};