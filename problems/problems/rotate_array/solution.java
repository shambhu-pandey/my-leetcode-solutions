class Solution {
    public void rotate(int[] nums, int k) {
        k =k%nums.length;
        reverse(nums,0,nums.length-1); // rotate all array
        reverse(nums,0 , k-1);         // rotate till k-1
        reverse(nums,k , nums.length-1);// rotate from k to n-1 size
    }


    public void reverse(int[] nums , int start ,int end){
        while(start<end){
            int temp= nums[start];
            nums[start] = nums[end];
            nums[end] = temp;
            start++;
            end--;
        }
    }
}