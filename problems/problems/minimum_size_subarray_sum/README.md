# 🚀 Minimum Size Subarray Sum

🔗 **LeetCode Link:**  
https://leetcode.com/problems/minimum-size-subarray-sum/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Array, Binary Search, Sliding Window, Prefix Sum

---

## 📖 Problem Description

Given an array of positive integers nums and a positive integer target, return the minimal length of a subarray whose sum is greater than or equal to target. If there is no such subarray, return 0 instead.

 
Example 1:


Input: target = 7, nums = [2,3,1,2,4,3]
Output: 2
Explanation: The subarray [4,3] has the minimal length under the problem constraint.


Example 2:


Input: target = 4, nums = [1,4,4]
Output: 1


Example 3:


Input: target = 11, nums = [1,1,1,1,1,1,1,1]
Output: 0


 
Constraints:


	1 <= target <= 109
	1 <= nums.length <= 105
	1 <= nums[i] <= 104


 
Follow up: If you have figured out the O(n) solution, try coding another solution of which the time complexity is O(n log(n)).

---

## 💻 My Solution

```cpp
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
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:16*
