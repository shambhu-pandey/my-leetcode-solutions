# 🚀 Max Consecutive Ones

🔗 **LeetCode Link:**  
https://leetcode.com/problems/max-consecutive-ones/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Array

---

## 📖 Problem Description

Given a binary array nums, return the maximum number of consecutive 1's in the array.

 
Example 1:


Input: nums = [1,1,0,1,1,1]
Output: 3
Explanation: The first two digits or the last three digits are consecutive 1s. The maximum number of consecutive 1s is 3.


Example 2:


Input: nums = [1,0,1,1,0,1]
Output: 2


 
Constraints:


	1 <= nums.length <= 105
	nums[i] is either 0 or 1.



---

## 💻 My Solution

```cpp
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:11*
