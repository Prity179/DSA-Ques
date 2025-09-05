class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int row = matrix.size();
        int col = matrix[0].size();
        vector<int> ans;

        int count = 0, total = row * col;
        int stRow = 0, stCol = 0;
        int endRow = row - 1, endCol = col - 1;

        while (count < total) {
            // Top row
            for (int index = stCol; count < total && index <= endCol; index++) {
                ans.push_back(matrix[stRow][index]);
                count++;
            }
            stRow++;

            // Right column
            for (int index = stRow; count < total && index <= endRow; index++) {
                ans.push_back(matrix[index][endCol]);
                count++;
            }
            endCol--;

            // Bottom row
            for (int index = endCol; count < total && index >= stCol; index--) {
                ans.push_back(matrix[endRow][index]);
                count++;
            }
            endRow--;

            // Left column
            for (int index = endRow; count < total && index >= stRow; index--) {
                ans.push_back(matrix[index][stCol]);
                count++;
            }
            stCol++;
        }
        return ans;
    }
};