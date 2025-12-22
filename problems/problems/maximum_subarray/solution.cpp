class Solution {
public:
    int maxSubArray(vector<int>& nums) {
        // Initialize maxSum with the first element of the array
        int maxsum = nums[0];
        int currsum = 0;

        for(int num : nums){
           // Either add current number to existing sum or start fresh with num
            currsum = max(num , currsum + num );
            // Update global maximum if currentSum is better
            maxsum = max(maxsum , currsum);
        }

        return maxsum;
    }
};