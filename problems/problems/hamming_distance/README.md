# 🚀 Hamming Distance

🔗 **LeetCode Link:**  
https://leetcode.com/problems/hamming-distance/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Bit Manipulation

---

## 📖 Problem Description

The Hamming distance between two integers is the number of positions at which the corresponding bits are different.

Given two integers x and y, return the Hamming distance between them.

 
Example 1:


Input: x = 1, y = 4
Output: 2
Explanation:
1   (0 0 0 1)
4   (0 1 0 0)
       ↑   ↑
The above arrows point to positions where the corresponding bits are different.


Example 2:


Input: x = 3, y = 1
Output: 1


 
Constraints:


	0 <= x, y <= 231 - 1


 
Note: This question is the same as  2220: Minimum Bit Flips to Convert Number.


---

## 💻 My Solution

```java
// Hamming Distance Kya Hoti Hai
// Definition:
// 👉 Do numbers ke binary representation me kitni positions different hain, 
// wahi Hamming Distance hai.
// Simple words:
// Jitne bits alag honge → utni Hamming Distance

// but hmlog thoda dusra method lga rhe hai xor wala 
// Steps yaad rakho:

// 1️⃣ XOR karo
// 2️⃣ 1s count karo

// Bas yehi Hamming Distance hai.
class Solution {
    public int hammingDistance(int x, int y) {
        
        int xor = x^y;
        int count =0;

        while(xor>0){
            if(xor%2==1){
                count++;
            }
            xor = xor/2;
        }
        return count;
    }
}

```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:21:33*
