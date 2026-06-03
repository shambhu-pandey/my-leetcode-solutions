class Solution {
public:

   int countSubset(vector<int>&nums , int target){
    int n = nums.size();

    vector<vector<int>> t(n+1, vector<int>(target+1 , 0));

    t[0][0] =1;

    for(int i =1;i<=n; i++){
      for(int j=0;j<=target;j++){
        if(nums[i-1]<=j){
            t[i][j] = (t[i-1][j-nums[i-1]] + t[i-1][j]);
        }else{
            t[i][j] = t[i-1][j];
        }
      }
    }
    return t[n][target];
   }


    int findTargetSumWays(vector<int>& nums, int target) {
        int sum=0;
    for(int x : nums){
        sum +=x;
    }
    if((target+sum)%2!=0 || abs(target)>sum){
         return 0;
    }
      // Required subset sum
        int s1 = (target + sum)/2;

        // Count subsets having sum = s1
        return countSubset(nums , s1);
    }  
};