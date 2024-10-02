vector <int> ans;


void leftside(TreeNode<int> *root){
    // cout<<root->data<<endl;

    if(root->left==NULL && root->right==NULL){
        return;
    }else{
        ans.push_back(root->data);
    }
    if(root->left==NULL) leftside(root->right);
    else leftside(root->left);
}
void leaves(TreeNode<int> *root){
    
    if(root==NULL) return;
    
    if(root->left==NULL && root->right==NULL){
        ans.push_back(root->data);
    }
    leaves(root->left);
    leaves(root->right);

}
void rightside(TreeNode<int> *root){
     if(root->left==NULL && root->right==NULL){
        return;
    }
    if(root->right==NULL) rightside(root->left);
    else rightside(root->right);
    ans.push_back(root->data);
}
vector<int> traverseBoundary(TreeNode<int> *root)
{
     if(root!=NULL) ans.push_back(root->data);
    //imp consider root separately and call on left and right subtree
    if(root->left)
    leftside(root->left);
    leaves(root);
    if(root->right)
    rightside(root->right);
    if(ans.size()>1 && ans[0]==ans[ans.size()-1]) ans.pop_back();
    return ans;
	// Write your code here.


}