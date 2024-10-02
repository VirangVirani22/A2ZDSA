bool ans;
int fun(Node *root){
   
   if(!root->left && !root->right) return root->data;
    int   l;
    if(root->left)
        l =fun(root->left);
    else
        l = 0;
    
    int r;
    if(root->right)
        r = fun(root->right);
    else
        r=0;
    //cout<<root->data<<" "<<l<<" "<<r<<endl;
    if((l+r)!=root->data) ans= false; 
    return root->data;
}
bool isParentSum(Node *root){
    // Write your code here.
    ans = true;
    fun(root);
    return ans;
}