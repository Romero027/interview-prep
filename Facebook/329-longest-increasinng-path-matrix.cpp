class Solution {
public:
    int longestIncreasingPath(vector<vector<int>>& matrix) {
        if( matrix.size() == 0 || matrix[0].size() == 0 )
            return 0;
        
        vector<vector<int>> cache(matrix.size(), vector<int>(matrix[0].size(), 0));
        int max_ = 0;
        
        for( int i = 0; i < matrix.size(); i++ ) {
            for( int j = 0; j < matrix[0].size(); j++ ) {
                int length = findSmallAround(i, j, matrix, cache, INT_MAX);//DFS + DP
                max_ = max(length, max_);
            }
        }
        return max_;
    }
    
    int findSmallAround(int i, int j, vector<vector<int>>& matrix, vector<vector<int>>& cache, int pre) {
         // if out of bond OR current cell value larger than previous cell value.
        if (i < 0 || i >= matrix.size() || j < 0 || j >= matrix[0].size() || matrix[i][j] >= pre) {
            return 0;
        }
        // if calculated before, no need to do it again
        if (cache[i][j] > 0) {
            return cache[i][j];
        } else {
            int cur = matrix[i][j];
            int tempMax = 0;
            tempMax = max(findSmallAround(i - 1, j, matrix, cache, cur), tempMax);
            tempMax = max(findSmallAround(i + 1, j, matrix, cache, cur), tempMax);
            tempMax = max(findSmallAround(i, j - 1, matrix, cache, cur), tempMax);
            tempMax = max(findSmallAround(i, j + 1, matrix, cache, cur), tempMax);
            cache[i][j] = ++tempMax;
            return tempMax;
        }
    }
};

