//SC : O(N)
class BSTIterator {
public:
    vector <int> v;
    int i=0;
    void fun(TreeNode *root)
    {
        if(root==NULL) return;
        fun(root->left);
        v.push_back(root->val);
        fun(root->right);
    }
    BSTIterator(TreeNode* root) {
        i=0;
        fun(root);
    }
    
    int next() {
        return v[i++];
    }
    
    bool hasNext() {
        
        if(i==v.size()) return false;
        return true;
    }
};
//SC : O(logN) / O(H)
class BSTIterator {
public:
    stack<TreeNode *> st;
    void fun(TreeNode *root){
        while(root){
            st.push(root);
            root = root->left;
        }
    }
    BSTIterator(TreeNode* root) {
       fun(root);
    }
    
    int next() {
        TreeNode* x =  st.top();
        st.pop();
        fun(x->right);
        
        return x->val;
    }
    
    bool hasNext() {
        return !st.empty();
    }
};