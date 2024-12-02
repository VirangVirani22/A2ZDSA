//SC : O(N)
class Solution {
public:
    void inorder(TreeNode* root) {
        if (!root) return;
        inorder(root->left);
        vec.push_back(root->val);
        inorder(root->right);
    }
    
    bool findTarget(TreeNode* root, int k) {
        inorder(root);
        int l = 0, r = vec.size()-1;
        while (l < r) {
            if (vec[l] + vec[r] == k) return true;
            else {
                if (vec[l] + vec[r] < k) l++;
                else r--;
            }
        }
        return false;
    }
    
private:
    vector<int> vec;
};

//Using BST Iterator for next() and prev() 
//SC : 2*O(H)

 class BSTNext{
    stack <TreeNode *> st;
    public:
    BSTNext(TreeNode *root){
        fun(root);
    }

    void fun(TreeNode *root){
        while(root) {
            st.push(root);
            root = root->left;
        }
    }

    int next(){
        TreeNode * x = st.top();
        st.pop();
        fun(x->right);
        return x->val;
    }

    bool hasnext(){
        return !st.empty();
    }
};
class BSTPrev{
    stack <TreeNode *> st;
    public:
    BSTPrev(TreeNode *root){
        fun(root);
    }

    void fun(TreeNode *root){
        while(root) {
            st.push(root);
            root = root->right;
        }
    }

    int prev(){
        TreeNode * x = st.top();
        st.pop();
        fun(x->left);
        return x->val;
    }

    bool hasprev(){
        return !st.empty();
    }
 };
class Solution {
public:
    
    bool findTarget(TreeNode* root, int k) {
        BSTNext n(root);
        BSTPrev p(root);
        int  i = n.next();
        int  j = p.prev();
        while(i<j){
            if(i+j==k)return true;
            else if(i+j<k) i = n.next();
            else j = p.prev();
        }
        return false;
    }
};