#include <iostream>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> luckyNumbers(vector<vector<int>>& matrix) {
        vector<int> result;
        int rows = matrix.size();
        int cols = matrix[0].size();

        for(int i = 0; i < rows; i++) {

            // Step 1: find min in row i
            int minVal = INT16_MAX;
            int minCol = -1;

            for(int j = 0; j < cols; j++) {
                if(matrix[i][j] < minVal) {
                    minVal = matrix[i][j];
                    minCol = j;
                }
            }

            // Step 2: check max in that column
            bool isLucky = true;
            for(int r = 0; r < rows; r++) {
                if(matrix[r][minCol] > minVal) {
                    isLucky = false;
                    break;
                }
            }

            if(isLucky) result.push_back(minVal);
        }

        return result;
    }
};


int main()
{
    vector<vector<int>> arr{
        {2, 5, 7, 9},
        {10, 12, 16, 20},
        {22, 23, 28, 29},
        {30, 33, 34, 38}};
    
    return 0;
}