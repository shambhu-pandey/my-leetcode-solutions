# 🚀 Permutations

🔗 **LeetCode Link:**  
https://leetcode.com/problems/permutations/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Backtracking

---

## 📖 Problem Description

Given an array nums of distinct integers, return all the possible permutations. You can return the answer in any order.

 
Example 1:
Input: nums = [1,2,3]
Output: [[1,2,3],[1,3,2],[2,1,3],[2,3,1],[3,1,2],[3,2,1]]
Example 2:
Input: nums = [0,1]
Output: [[0,1],[1,0]]
Example 3:
Input: nums = [1]
Output: [[1]]

 
Constraints:


	1 <= nums.length <= 6
	-10 <= nums[i] <= 10
	All the integers of nums are unique.



---

## 💻 My Solution

```cpp
class Solution {
    private:
    void solve(vector<int> nums , int index , vector<vector<int>>& ans){
        if(index>=nums.size()){
            ans.push_back(nums);
            return;
        }
        for(int j = index ; j<nums.size();j++){
            swap(nums[index] , nums[j]);
            solve(nums , index+1 , ans);

            //backtrack
            swap(nums[index] , nums[j]);
        }
    }
public:
    vector<vector<int>> permute(vector<int>& nums) {
        vector<vector<int>> ans;
        int index =0;

        solve(nums , index , ans);
        return ans;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:18*
