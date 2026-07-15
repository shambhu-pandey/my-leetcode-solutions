# 🚀 Reverse Integer

🔗 **LeetCode Link:**  
https://leetcode.com/problems/reverse-integer/

---

## 🎯 Difficulty

**Medium**

---

## 🏷️ Tags

Math

---

## 📖 Problem Description

Given a signed 32-bit integer x, return x with its digits reversed. If reversing x causes the value to go outside the signed 32-bit integer range [-231, 231 - 1], then return 0.

Assume the environment does not allow you to store 64-bit integers (signed or unsigned).

 
Example 1:


Input: x = 123
Output: 321


Example 2:


Input: x = -123
Output: -321


Example 3:


Input: x = 120
Output: 21


 
Constraints:


	-231 <= x <= 231 - 1



---

## 💻 My Solution

```cpp
class Solution {
public:
    int reverse(int x) {
       int temp = x ;
       int rev =0;
       while(temp !=0){
        int digit   = (temp) % 10;
        if(rev > INT_MAX/10 || (rev == INT_MAX/10 && digit >7 )) return 0;
        if(rev < INT_MIN/10 || (rev ==INT_MIN/10 && digit < -8)) return 0;
        rev = (rev*10) + digit;
        temp = temp/10;
       }

       return rev ;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:20:54*
