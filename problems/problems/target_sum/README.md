# 🚀 Target Sum

🔗 **LeetCode Link:**  
https://leetcode.com/problems/target-sum/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Dynamic Programming, Backtracking

---

## 📖 Problem Description

You are given an integer array nums and an integer target.

You want to build an expression out of nums by adding one of the symbols '+' and '-' before each integer in nums and then concatenate all the integers.


	For example, if nums = [2, 1], you can add a '+' before 2 and a '-' before 1 and concatenate them to build the expression "+2-1".


Return the number of different expressions that you can build, which evaluates to target.

 
Example 1:


Input: nums = [1,1,1,1,1], target = 3
Output: 5
Explanation: There are 5 ways to assign symbols to make the sum of nums be target 3.
-1 + 1 + 1 + 1 + 1 = 3
+1 - 1 + 1 + 1 + 1 = 3
+1 + 1 - 1 + 1 + 1 = 3
+1 + 1 + 1 - 1 + 1 = 3
+1 + 1 + 1 + 1 - 1 = 3


Example 2:


Input: nums = [1], target = 1
Output: 1


 
Constraints:


	1 <= nums.length <= 20
	0 <= nums[i] <= 1000
	0 <= sum(nums[i]) <= 1000
	-1000 <= target <= 1000



---

## 💻 My Solution

```cpp
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:55*
