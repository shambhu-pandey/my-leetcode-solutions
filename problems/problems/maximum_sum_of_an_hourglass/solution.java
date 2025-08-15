class Solution {
    public int maxSum(int[][] mat) {
        int n = mat.length;
        int m = mat[0].length;
        if(n<3 || m<3){
            return -1;
        }
        int ans = Integer.MIN_VALUE;
      

        for(int i = 0 ; i < n-2;i++){
            for(int j= 0; j < m-2;j++){
               int sum =mat[i][j] + mat[i][j+1] + mat[i][j+2] +mat[i+1][j+1]+ mat[i+2][j]+ mat[i+2][j+1]+mat[i+2][j+2];
                if(sum>ans){
                    ans= sum;
                }
            }
        }
        return ans;
    }
};