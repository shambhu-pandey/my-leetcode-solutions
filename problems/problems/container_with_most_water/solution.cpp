class Solution {
public:
    int maxArea(vector<int>& height) {
       
       int i =0; 
       int j = height.size()-1;

      int maxarea =0;

       while(i<j){

        int h = min(height[i] , height[j]);
        int width = j-i;

        int area = h*width;
        //update area
        maxarea = max(area , maxarea);
       
       //move smaller height pointer
        if(height[i] < height[j]){
            i++;
        }
        else{
            j--;
        }
       }

       return maxarea;
    }
};