vector<int> levelOrder(TreeNode<int> * root){
    // Write your code here.
    queue < TreeNode<int>* > q;
    vector <int> ans;
    q.push(root);
    while(!q.empty()){
        int sz = q.size();
        
        for(int i=0;i<sz;i++){
            TreeNode<int> * node = q.front();
            q.pop();
            ans.push_back(node->data);
            if(node->left!=NULL){
                q.push(node->left);
            }
            if(node->right!=NULL){
                q.push(node->right);
            }


        }
        

    }
    return ans;
}
