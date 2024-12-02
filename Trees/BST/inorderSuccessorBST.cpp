class Solution{
  public:
    // returns the inorder successor of the Node x in BST (rooted at 'root')
    Node * inOrderSuccessor(Node *root, Node *x)
    {
       Node* insucc = NULL;
       while(root){
           if(root->data>x->data){
               insucc = root;
               root = root->left;
           }else{
               root = root->right;
           }
       }
       return insucc;
    }
};