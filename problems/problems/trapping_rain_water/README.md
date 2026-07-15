# 🚀 Trapping Rain Water

🔗 **LeetCode Link:**  
https://leetcode.com/problems/trapping-rain-water/

---

## 🎯 Difficulty

**Hard**

---

## 🏷️ Tags

Array, Two Pointers, Dynamic Programming, Stack, Monotonic Stack

---

## 📖 Problem Description

Given n non-negative integers representing an elevation map where the width of each bar is 1, compute how much water it can trap after raining.

 
Example 1:


Input: height = [0,1,0,2,1,0,1,3,2,1,2,1]
Output: 6
Explanation: The above elevation map (black section) is represented by array [0,1,0,2,1,0,1,3,2,1,2,1]. In this case, 6 units of rain water (blue section) are being trapped.


Example 2:


Input: height = [4,2,0,3,2,5]
Output: 9


 
Constraints:


	n == height.length
	1 <= n <= 2 * 104
	0 <= height[i] <= 105



---

## 💻 My Solution

```cpp
class Solution {
public:
    int trap(vector<int>& height) {
        int left =0;
        int right = height.size()-1;

        int leftmax =height[left];
        int rightmax=height[right];
        int water =0;
        while(left<right){
               if(leftmax < rightmax){
                left++;
                leftmax = max(leftmax , height[left]);
                water =  water + leftmax - height[left]; // height of left means block 
               }
               else{
                right--;
                rightmax = max(rightmax , height[right]);
                water = water + rightmax -height[right];
               }
        }
          return water;
    }
  
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:22*
