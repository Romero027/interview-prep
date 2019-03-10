//Reference:https://leetcode.com/problems/range-sum-query-2d-immutable/discuss/75350/Clean-C%2B%2B-Solution-and-Explaination-O(mn)-space-with-O(1)-time

class NumMatrix {
public:
    NumMatrix(vector<vector<int>> matrix):row(matrix.size()), col(row == 0 ? 0: matrix[0].size())
            , sums(row+1, vector<int>(col+1 , 0)){
        for(int i = 1; i <= row; i++ ) {
            for(int j = 1; j <= col; j++){
                sums[i][j] = sums[i-1][j] + sums[i][j-1] - sums[i-1][j-1] + matrix[i-1][j-1];
            }
        }
        
    }
    
    int sumRegion(int row1, int col1, int row2, int col2) {
        return sums[row2+1][col2+1] - sums[row2+1][col1] - sums[row1][col2+1] + sums[row1][col1];
    }
    int row, col;
    vector<vector<int>> sums;
};

/**
 * Your NumMatrix object will be instantiated and called as such:
 * NumMatrix obj = new NumMatrix(matrix);
 * int param_1 = obj.sumRegion(row1,col1,row2,col2);
 */