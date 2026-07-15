# 🚀 Power of Two

🔗 **LeetCode Link:**  
https://leetcode.com/problems/power-of-two/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Math, Bit Manipulation, Recursion

---

## 📖 Problem Description

Given an integer n, return true if it is a power of two. Otherwise, return false.

An integer n is a power of two, if there exists an integer x such that n == 2x.

 
Example 1:


Input: n = 1
Output: true
Explanation: 20 = 1


Example 2:


Input: n = 16
Output: true
Explanation: 24 = 16


Example 3:


Input: n = 3
Output: false


 
Constraints:


	-231 <= n <= 231 - 1


 
Follow up: Could you solve it without loops/recursion?

---

## 💻 My Solution

```java
// Count set bits.
// If set bits = 1 → power of two

class Solution {
    public boolean isPowerOfTwo(int n) {
        
        if(n<=0) return false;
        
        while(n%2==0){
            n=n/2;
        }
        if(n==1){
            return true;
        }
        else{
            return false;
        }


                
        // int count =0;
        // while(n>0){
        //     if(n%2==1){
        //         count++;
        //     }
        //     n= n/2;
        // }
        // if(count ==1){
        //     return true;
        // }
        // else{
        //     return false;
        // }

    }
}
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:56*
