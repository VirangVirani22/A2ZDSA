bool fun(TreeNode<int> *root1,TreeNode<int> *root2){
    if(root1==NULL || root2==NULL ) return root1==root2;
    if(root1->data!=root2->data) return false;
    return fun(root1->left,root2->right) && fun(root1->right,root2->left);
}
bool isSymmetric(TreeNode<int> *root)
{
    // Write your code here
    return fun(root->left,root->right);
}