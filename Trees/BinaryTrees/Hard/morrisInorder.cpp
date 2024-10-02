class Solution {
public:
    vector<int> inorderTraversal(TreeNode* root) {
        vector <int> in;
        TreeNode* cur = root;
        while(cur!=NULL){
            if(cur->left==NULL){
                in.push_back(cur->val);
                cur = cur->right;
            }
            else{
                 TreeNode* last = cur->left;
                 while(last->right!=NULL && last->right!=cur){
                    last = last->right;
                 }
                 if(last->right==NULL){
                    last->right = cur;
                    cur = cur->left;
                 }else{
                    last->right=NULL;
                    in.push_back(cur->val);
                    cur=cur->right;
                 }
            }
        }
        return in;
    }
};