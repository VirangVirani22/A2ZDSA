class Solution {
public:
    TreeNode* insertIntoBST(TreeNode* root, int val) {
        TreeNode *pre = NULL;
        TreeNode *head = root;
        TreeNode *newnode = new  TreeNode(val);
        if(!root) return newnode;
        while(root){
            pre = root;
            if(root->val>val){
                root = root->left;
            }else{
                root = root->right;
            }
            
        }
       
        if(pre->val>val){
            pre->left = newnode;
        }else{
            pre->right = newnode;
        }
        return head;
    }
};