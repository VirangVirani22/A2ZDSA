int ans;
int fun(TreeNode<int> *root){
    if(root==NULL) return 0;
    int l = fun(root->left);
    int r = fun(root->right);
    ans = max(ans,l+r);
    return max(l,r)+1;
}
int diameterOfBinaryTree(TreeNode<int> *root){
	// Write Your Code Here
    ans=0;
    fun(root);
    return ans;
    
}