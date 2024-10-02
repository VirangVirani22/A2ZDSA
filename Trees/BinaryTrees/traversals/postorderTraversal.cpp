vector <int> ans;
void postorder(TreeNode *root){
    if(root!=NULL){
        postorder(root->left);
        postorder(root->right);
        ans.push_back(root->data);
    }
}
vector<int> postorderTraversal(TreeNode *root)
{
    postorder(root);
    return ans;
    // Write your code here.
}