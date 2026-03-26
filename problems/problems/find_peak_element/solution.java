// Use Binary Search → O(log n)
// Compare only mid and mid+1 (not both sides)
// Downhill (>) → peak on left
// Uphill (<) → peak on right
// Always guaranteed peak exists
// (because edges = -∞)
// No duplicates 
class Solution {
    public int findPeakElement(int[] nums) {

     int left = 0;
     int right = nums.length -1;
    
    while(left<right){
        int mid = left + (right-left)/2;

        if(nums[mid]> nums[mid+1]){
            right = mid; //peak is on the right side 
        } else{
            //peak is on the right side 
            left = mid+1;
        }
    }

    return left; // or right  (both same at the end)
    } 
}