//approch 1: same as preorder but reverse link
class Solution {
public:
    vector<int> postorderTraversal(TreeNode* root) {
        vector <int> post;
        TreeNode *cur = root;
        while(cur!=NULL){
            if(cur->right==NULL){
                post.push_back(cur->val);
                cur = cur->left;
            }else{
                TreeNode *last = cur->right;
                while(last->left!=NULL && last->left!=cur){
                    last=last->left;
                }
                if(last->left==NULL){
                    post.push_back(cur->val);
                    last->left=cur;
                    cur = cur->right;
                }else{
                    last->left=NULL;
                    cur = cur->left;
                }
            }
        }
        reverse(post.begin(),post.end());
        return post;
    }
};
