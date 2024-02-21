//brute forece : o(n*m)
//better : search only in candidate row o(n + logm)
//binary search :o(n*m)
bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int n = matrix.size();
        int m = matrix[0].size();

        int low = 0, high = n*m - 1;
        while(low<=high){
            int mid = low + (high - low)/2;
            int row = mid / m;
            int col = mid % m;
            // cout<<mid<<" "<<row<<" "<<col<<endl;
            if(matrix[row][col] ==  target) return true;
            else if(matrix[row][col] < target) low = mid + 1;
            else high = mid - 1;
        }
        
        return false;
}

//another : o(n + m) when row and column wise sorted
class Solution {
public:
    bool searchMatrix(vector<vector<int>>& mat, int tar) {
        int n=mat.size();
        int m=mat[0].size();
        int i=0,j=m-1;
        while(i<n && j>=0)
        {
            if(mat[i][j]==tar) return true;
            if(mat[i][j]<tar)
            {
                i++;
            }
            else
                j--;
        }
        return false;
    }
};