vector <int> ans;
void inorder(TreeNode *root){
    if(root!=NULL){
        inorder(root->left);
        ans.push_back(root->data);
        inorder(root->right);
    }
}
vector<int> getInOrderTraversal(TreeNode *root)
{
    // Write your code here.
    inorder(root);
    return ans;
}