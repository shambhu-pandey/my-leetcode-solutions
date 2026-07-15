# 🚀 Palindrome Number

🔗 **LeetCode Link:**  
https://leetcode.com/problems/palindrome-number/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Math

---

## 📖 Problem Description

Given an integer x, return true if x is a palindrome, and false otherwise.

 
Example 1:


Input: x = 121
Output: true
Explanation: 121 reads as 121 from left to right and from right to left.


Example 2:


Input: x = -121
Output: false
Explanation: From left to right, it reads -121. From right to left, it becomes 121-. Therefore it is not a palindrome.


Example 3:


Input: x = 10
Output: false
Explanation: Reads 01 from right to left. Therefore it is not a palindrome.


 
Constraints:


	-231 <= x <= 231 - 1


 
Follow up: Could you solve it without converting the integer to a string?

---

## 💻 My Solution

```cpp
class Solution {
public:
    bool isPalindrome(int x) {
        
        if(x<0 || (x%10==0 && x!=0)){
            return false;
        }
        long long reversedNum =0;
        int original = x;

        while(x>0){
            int lastDigit= x%10;   // last digit nikaal liye 
            reversedNum = (reversedNum*10)+ lastDigit;
            x /=10;
        }
        return reversedNum == original;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:23*
