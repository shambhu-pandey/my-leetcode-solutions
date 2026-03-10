class Solution {
    
    public static int gcd(int a , int b){
        while(b!=0){
          int temp = b;
          b = a%b;
          a = temp;
        }
        return a;
    }
    
    public boolean isGoodArray(int[] nums) {
        int g = nums[0];

       for(int i = 1; i<nums.length ; i++){
         g = gcd(g , nums[i]);
       }

       return g== 1;
    }
}