class Solution{
    public:
    /*You are required to complete this method */
    // Return the size of the largest sub-tree which is also a BST
    ReturnValue fun(Node* root){
        if(root==NULL) return ReturnValue(0,INT_MAX,INT_MIN);
        ReturnValue l = fun(root->left);
        ReturnValue r = fun(root->right);
        if(l.maxVal<root->data && root->data<r.minVal){
            return ReturnValue(l.sz+r.sz+1,min(l.minVal,root->data),max(r.maxVal,root->data));
        }else{
            return ReturnValue(max(l.sz,r.sz),INT_MIN,INT_MAX);
        }
    }
    int largestBst(Node *root)
    {
    	return fun(root).sz;
    }
};