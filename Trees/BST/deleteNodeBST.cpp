class Solution {
public:
    TreeNode* inorderPred(TreeNode *root){
        TreeNode* inpred = root->left;
        while(inpred->right){
            inpred = inpred->right;
        }
        return inpred;
    }
    TreeNode* del(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val>key) root->left = del(root->left,key);
        else if(root->val<key) root->right = del(root->right,key);
        else{
            if(root->right==NULL) return root->left;
            else if(root->left==NULL) return root->right;
            else{
                TreeNode *inpre = inorderPred(root);
                root->val = inpre->val;

                root->left = del(root->left,inpre->val);
                return root;
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        return del(root,key);
       
        
    }
};class Solution {
public:
    TreeNode* inorderPred(TreeNode *root){
        TreeNode* inpred = root->left;
        while(inpred->right){
            inpred = inpred->right;
        }
        return inpred;
    }
    TreeNode* del(TreeNode* root,int key){
        if(root==NULL) return NULL;
        if(root->val>key) root->left = del(root->left,key);
        else if(root->val<key) root->right = del(root->right,key);
        else{
            if(root->right==NULL) return root->left;
            else if(root->left==NULL) return root->right;
            else{
                TreeNode *inpre = inorderPred(root);
                root->val = inpre->val;

                root->left = del(root->left,inpre->val);
                return root;
            }
        }
        return root;
    }
    TreeNode* deleteNode(TreeNode* root, int key) {
       
        return del(root,key);
       
        
    }
};