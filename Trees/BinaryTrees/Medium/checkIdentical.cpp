bool identicalTrees(BinaryTreeNode<int>* root1, BinaryTreeNode<int>* root2) {
    // Write your code here. 	 
    if(root1==NULL && root2==NULL) return true;
    if(root1==NULL || root2==NULL) return false;
    if(root1->data!=root2->data) return false;
    bool l= identicalTrees(root1->left,root2->left);
    bool r = identicalTrees(root1->right,root2->right);
    return l & r;
}