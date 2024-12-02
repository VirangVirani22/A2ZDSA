int findCeil(Node* root, int n) {
    if (root == NULL) return -1;
    int ans = -1;
    while(root){
        if(root->data>=n){
            ans = root->data;
            root = root->left;
        }else{
            root = root->right;
        }
    }
    return ans;
}