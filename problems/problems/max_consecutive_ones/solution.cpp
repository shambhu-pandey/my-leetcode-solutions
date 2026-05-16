class Solution {
public:
    int findMaxConsecutiveOnes(vector<int>& nums) {
        int n = nums.size();

        int curr_count =0;
        int  maxCount =0;
        for(int i =0; i<n; i++){
            if(nums[i]==1){
                    curr_count++;  
            }
            else{
                maxCount  = max(curr_count ,maxCount);
                curr_count=0;
            }
        }
        return max(curr_count , maxCount);
    }
};