class Solution {
  public:
    int minValue(Node* root) {
        // Code here
        int mn = INT_MAX;
        while(root){
            mn = min(mn,root->data);
            root = root->left;
        }
        return mn;
    }
};