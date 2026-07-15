# 🚀 Move Zeroes

🔗 **LeetCode Link:**  
https://leetcode.com/problems/move-zeroes/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Array, Two Pointers

---

## 📖 Problem Description

Given an integer array nums, move all 0's to the end of it while maintaining the relative order of the non-zero elements.

Note that you must do this in-place without making a copy of the array.

 
Example 1:
Input: nums = [0,1,0,3,12]
Output: [1,3,12,0,0]
Example 2:
Input: nums = [0]
Output: [0]

 
Constraints:


	1 <= nums.length <= 104
	-231 <= nums[i] <= 231 - 1


 
Follow up: Could you minimize the total number of operations done?

---

## 💻 My Solution

```cpp
class Solution {
public:
    void moveZeroes(vector<int>& nums) {
        int n = nums.size();
        int left =0;
        for(int right = 0; right<n;right++){
            if(nums[right]!=0){
            swap(nums[left] , nums[right]);
            left++;
            }
        }
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:09*
