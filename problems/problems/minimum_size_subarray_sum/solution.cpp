class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {

        int n = nums.size();

        int left = 0;          // window start
        int sum = 0;           // current window sum
        int ans = INT_MAX;     // minimum length

        // right pointer window ko expand karega
        for(int right = 0; right < n; right++) {

            sum += nums[right];

            // jab tak sum target se bada ya equal hai
            while(sum >= target) {

                int len = right - left + 1;

                ans = min(ans, len);

                // left element hata do
                sum -= nums[left];

                left++;
            }
        }

        // agar koi subarray nahi mila
        if(ans == INT_MAX)
            return 0;

        return ans;
    }
};