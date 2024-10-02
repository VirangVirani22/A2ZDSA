vector <string> ans;
void fun(BinaryTreeNode<int> * root,string s){
    //   cout<<root->data<<" "<<s<<endl;
     if(root==NULL) return;
  if (root->left == NULL && root->right == NULL) {
    //   cout<<"leaf"<<endl;
       s+=(to_string(root->data));
    //    cout<<s<<endl;
       ans.push_back(s);
        return;
  }
 
    s+=(to_string(root->data));
    s+=" ";
    fun(root->left,s);
    fun(root->right,s);
}
vector <string> allRootToLeaf(BinaryTreeNode<int> * root) {
    // Write your code here.
    fun(root,"");
    return ans;

}