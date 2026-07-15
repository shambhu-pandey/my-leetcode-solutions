# 🚀 Valid Palindrome II

🔗 **LeetCode Link:**  
https://leetcode.com/problems/valid-palindrome-ii/

---

## 🎯 Difficulty

**Easy**

---

## 🏷️ Tags

Two Pointers, String, Greedy

---

## 📖 Problem Description

Given a string s, return true if the s can be palindrome after deleting at most one character from it.

 
Example 1:


Input: s = "aba"
Output: true


Example 2:


Input: s = "abca"
Output: true
Explanation: You could delete the character 'c'.


Example 3:


Input: s = "abc"
Output: false


 
Constraints:


	1 <= s.length <= 105
	s consists of lowercase English letters.



---

## 💻 My Solution

```cpp
class Solution {
public:
    bool validPalindrome(string s) {
        int left =0;
        int right = s.size()-1;

       
        while(left<right){
            if(s[left] != s[right]){
                // yha par fun ko string left aur right pointer bhej rhe hai pahle      left pointer ko ek delete kar ke dekh rhe hai phir ki palindrome bn ja rha hai ki nhi aur phir ek baar right pointer ko ek delete kar ke dekh rhe hai ki palindrome bn ja rha hai ki nhi   
                return isPalindrome(s , left+1 , right) ||
                        isPalindrome(s,left, right-1);
            }
            left++;
            right--;
        }
         return true;
    }
 
 // simple palindrome check karne ka logic 
    private:
     bool isPalindrome(string &s , int left , int right){
        while(left<right){
            if(s[left]!=s[right]){
                return false;
            }
            left++;
            right--;
        }
        return true;
    }
};
```

---

## 📝 Approach

- Refer to the solution code above for the approach used.

---

*Generated on 2026-07-15 21:22:02*
