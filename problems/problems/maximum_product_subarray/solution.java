class Solution {
        public int maxProduct(int[] nums){
            int ans = Integer.MIN_VALUE;
            int currentProduct = 1;

          // 1st pass
          for(int i = 0 ; i < nums.length; i++){
            currentProduct *=nums[i];
            ans = Math.max(ans, currentProduct);
            if(currentProduct==0){
                currentProduct=1;
            }
          }
          
          currentProduct=1;
        //   2nd pass
          for(int i = nums.length-1 ; i>=0;i--){
            currentProduct *=nums[i];
            ans = Math.max(ans, currentProduct);
            if(currentProduct==0){
                currentProduct=1;
            }
          }
           return ans;
        }
}