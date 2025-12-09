class Solution {
public:
    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        int row = matrix.size();
        int column = matrix[0].size();

        int rowIndex = 0;   
        int columnIndex = column-1 ;

        while(rowIndex < row && columnIndex >=0 ){
            int element = matrix[rowIndex][columnIndex];

            if(element == target){
                return 1;
            }

            else if(element < target){
                rowIndex++;
            }
            else{
                columnIndex--;
            }
        }
        return 0;
    }
};