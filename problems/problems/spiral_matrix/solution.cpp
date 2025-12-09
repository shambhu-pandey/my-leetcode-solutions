class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        if(matrix.empty() || matrix[0].empty()) return {};

        vector<int> ans;
        int row = matrix.size();
        int col = matrix[0].size();

        int count = 0;
        int total = row*col;

        int startingRow = 0;
        int endingCol = col-1;
        int endingRow = row-1;
        int startingCol = 0;

       while(count<total){

        // print starting row;
        for(int index = startingCol ; count<total && index <= endingCol ; index++){
            ans.push_back(matrix[startingRow][index]);
            count++;
        }
        startingRow++;

        //print ending col
        for(int index = startingRow ; count<total && index <= endingRow;index++ ){
            ans.push_back(matrix[index][endingCol]);
            count++;
       }
       endingCol--;

       //print ending row
    
       for(int index= endingCol; count<total && index>= startingCol;index-- ){
        ans.push_back(matrix[endingRow][index]);
        count++;
       }
       endingRow--;
       
       //print staringCol
       
       for(int index= endingRow ; count<total &&  index>=startingRow ;index--){
        ans.push_back(matrix[index][startingCol]);
        count++;
       }
       startingCol++;
       }
             return ans;
    }

    
};