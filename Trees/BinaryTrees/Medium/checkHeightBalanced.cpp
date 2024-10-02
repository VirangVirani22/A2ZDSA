bool ans;
int fun(TreeNode<int>* root){
    if(root==NULL) return 0;
    int l = fun(root->left);
    int r = fun(root->right);

    if(abs(l-r)>1) ans = false;;
    return max(l,r)+1;
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here.
    ans = true;
    fun(root);
    return ans;
}

//without global variable
int fun(TreeNode<int>* root){
    if(root==NULL) return 0;
    int l = fun(root->left);
    int r = fun(root->right);
    if(l==-1 ||  r==-1) return -1;
 
    if(abs(l-r)>1) return-1;;
    return max(l,r)+1;
}
bool isBalancedBT(TreeNode<int>* root){
    // Write your code here
    return fun(root)!=-1;
    
}