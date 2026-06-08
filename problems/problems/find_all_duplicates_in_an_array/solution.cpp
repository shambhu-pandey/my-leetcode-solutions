class Solution {
public:
    vector<int> findDuplicates(vector<int>& nums) {
        int n = nums.size();
        
        sort(nums.begin() , nums.end());
        vector<int>ans;

        for(int i =1; i<n; i++){
            // duplicate mila
           if(nums[i] == nums[i-1]){

            // Same duplicate baar baar add na ho
            if(ans.empty() || ans.back() != nums[i]){
            ans.push_back(nums[i]);
            }
           }
        }

        return ans;
    }
};