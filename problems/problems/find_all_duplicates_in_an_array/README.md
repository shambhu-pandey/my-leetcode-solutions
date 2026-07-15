# 🚀 Find All Duplicates in an Array

🔗 **LeetCode Link:**  
https://leetcode.com/problems/find-all-duplicates-in-an-array/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Hash Table, Sorting

---

## 📖 Problem Description

Given an integer array nums of length n where all the integers of nums are in the range [1, n] and each integer appears at most twice, return an array of all the integers that appears twice.

You must write an algorithm that runs in O(n) time and uses only constant auxiliary space, excluding the space needed to store the output

 
Example 1:
Input: nums = [4,3,2,7,8,2,3,1]
Output: [2,3]
Example 2:
Input: nums = [1,1,2]
Output: [1]
Example 3:
Input: nums = [1]
Output: []

 
Constraints:


	n == nums.length
	1 <= n <= 105
	1 <= nums[i] <= n
	Each element in nums appears once or twice.



---

## 💻 My Solution

```cpp
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:50*
