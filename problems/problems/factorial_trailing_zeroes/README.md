# 🚀 Factorial Trailing Zeroes

🔗 **LeetCode Link:**  
https://leetcode.com/problems/factorial-trailing-zeroes/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Math

---

## 📖 Problem Description

Given an integer n, return the number of trailing zeroes in n!.

Note that n! = n * (n - 1) * (n - 2) * ... * 3 * 2 * 1.

 
Example 1:


Input: n = 3
Output: 0
Explanation: 3! = 6, no trailing zero.


Example 2:


Input: n = 5
Output: 1
Explanation: 5! = 120, one trailing zero.


Example 3:


Input: n = 0
Output: 0


 
Constraints:


	0 <= n <= 104


 
Follow up: Could you write a solution that works in logarithmic time complexity?


---

## 💻 My Solution

```java
class Solution {
    public int trailingZeroes(int n) {
        int count = 0;

        while(n>0){
            n = n/5;
            count = count + n;
        }

        return count;
    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:44*
