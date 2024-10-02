int lowestCommonAncestor(TreeNode<int> *root, int x, int y)
{
	
    //    Write your code here
    if(root==NULL) return -1;
    int l = lowestCommonAncestor(root->left,x,y);
    int r = lowestCommonAncestor(root->right,x,y);
    // cout<<root->data<<" "<<l<<" "<<r<<endl;S
    if(root->data==x || root->data==y) return root->data;
    if(l==-1 && r==-1) return -1;
     if(l!=-1 && r!=-1) return root->data;
    if(l!=-1) {
        return l;
    }
    if(r!=-1) {
        return r;
    }

}