vector<int> zigZagTraversal(BinaryTreeNode<int> *root)
{
    // Write your code here!

    vector<int> ans;
    if(root==NULL) return ans;
    queue<BinaryTreeNode<int> *> q;
    q.push(root);
    bool zig = true;
    while(!q.empty()){

        // cout<<zig<<endl;
        int s = q.size();
        vector<int> temp;
        for(int i=0;i<s;i++){
            BinaryTreeNode<int>* node = q.front();
            q.pop();
            //cout<<node->data<<endl;
            temp.push_back(node->data);
            if(node->left!=NULL) q.push(node->left);
            if(node->right!=NULL) q.push(node->right);

        }
        
        if(zig){
            ans.insert(ans.end(),temp.begin(),temp.end());
          
        }else{
              ans.insert(ans.end(),temp.rbegin(),temp.rend());
        }
        // for(auto x:ans) cout<<x<<" ";
        // cout<<endl;
        zig =  !zig;

    }
    return ans;
} 